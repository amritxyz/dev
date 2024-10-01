#!/usr/bin/env bash

# Define variables
HOSTNAME="nyx"
TIMEZONE="Asia/Kathmandu"
LOCALE="en_US.UTF-8"
KEYMAP="us"
DISK="/dev/sda"  # Change this to your disk
ROOT_PARTITION="${DISK}1"
SWAP_PARTITION="${DISK}2"
USER_NAME="void"
PASSWORD="main"  # Change this for a more secure password
SWAP_SIZE="4G"  # Change this as needed

# Update the system clock
timedatectl set-ntp true

# Partition the disk
echo "Partitioning the disk..."
(
echo o      # Create a new empty DOS partition table
echo n      # New partition
echo p      # Primary
echo 1      # Partition number
echo        # Default - first sector
echo +20G   # Size of the root partition
echo n      # New partition
echo p      # Primary
echo 2      # Partition number
echo        # Default - first sector
echo +${SWAP_SIZE} # Size of the swap partition
echo n      # New partition
echo p      # Primary
echo 3      # Partition number
echo        # Default - first sector
echo        # Use the rest of the disk
echo w      # Write changes
) | fdisk $DISK

# Format partitions
echo "Formatting partitions..."
mkfs.ext4 $ROOT_PARTITION
mkswap $SWAP_PARTITION
swapon $SWAP_PARTITION

# Mount the root partition
mount $ROOT_PARTITION /mnt

# Install base system
echo "Installing base system..."
pacstrap /mnt base linux linux-firmware vim nano

# Generate fstab
echo "Generating fstab..."
genfstab -U /mnt >> /mnt/etc/fstab

# Chroot into the new system
arch-chroot /mnt /bin/bash <<EOF

# Set timezone
echo "Setting timezone..."
ln -sf /usr/share/zoneinfo/$TIMEZONE /etc/localtime
hwclock --systohc

# Set locale
echo "Setting locale..."
echo "$LOCALE UTF-8" >> /etc/locale.gen
locale-gen
echo "LANG=$LOCALE" > /etc/locale.conf

# Set keymap
echo "Setting keymap..."
echo "KEYMAP=$KEYMAP" > /etc/vconsole.conf

# Set hostname
echo "Setting hostname..."
echo "$HOSTNAME" > /etc/hostname

# Create initramfs
echo "Creating initramfs..."
mkinitcpio -P

# Set root password
echo "Setting root password..."
echo "root:$PASSWORD" | chpasswd

# Create a new user
echo "Creating user $USER_NAME..."
useradd -m -G wheel $USER_NAME
echo "$USER_NAME:$PASSWORD" | chpasswd

# Install and configure sudo
pacman -S --noconfirm sudo
echo "%wheel ALL=(ALL) ALL" >> /etc/sudoers

EOF

# Unmount and reboot
echo "Unmounting and rebooting..."
umount -R /mnt
reboot
