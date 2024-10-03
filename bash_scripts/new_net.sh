#!/bin/sh

# Define configuration file location
CONF_DIR="/etc/NetworkManager/conf.d"
CONF_FILE="$CONF_DIR/wifi-powersave.conf"

# Function to print messages in green
print_success() {
    echo -e "\033[0;32m$1\033[0m"
}

# Function to print messages in red
print_error() {
    echo -e "\033[0;31m$1\033[0m"
}

# Check if script is run as root
if [ "$(id -u)" -ne "0" ]; then
    print_error "This script must be run as root. Use 'sudo' to execute it."
    exit 1
fi

# Create the configuration directory if it doesn't exist
if ! mkdir -p "$CONF_DIR"; then
    print_error "Failed to create directory $CONF_DIR"
    exit 1
fi

# Create or overwrite the configuration file with the desired settings
if ! echo -e "[connection]\nwifi.powersave = 2" | tee "$CONF_FILE" > /dev/null; then
    print_error "Failed to write to $CONF_FILE"
    exit 1
fi

# Display the contents of the configuration file
print_success "The following has been added to $CONF_FILE:"
cat "$CONF_FILE"
echo

# Restart the NetworkManager service
if command -v systemctl > /dev/null; then
    if systemctl is-active --quiet NetworkManager; then
        print_success "Restarting NetworkManager service..."
        if ! systemctl restart NetworkManager; then
            print_error "Failed to restart NetworkManager service with systemctl"
            exit 1
        fi
        print_success "NetworkManager service restarted successfully."
    else
        print_error "NetworkManager service is not running. Please start it manually."
        exit 1
    fi
elif command -v sv > /dev/null; then
    if sv status NetworkManager > /dev/null; then
        print_success "Restarting NetworkManager service..."
        if ! sv down NetworkManager || ! sv up NetworkManager; then
            print_error "Failed to restart NetworkManager service with sv"
            exit 1
        fi
        print_success "NetworkManager service restarted successfully."
    else
        print_error "NetworkManager service is not running. Please start it manually."
        exit 1
    fi
else
    print_error "Neither systemctl nor sv found. Unable to manage NetworkManager service."
    exit 1
fi
