#!/bin/sh
cat /etc/fstab | grep none > "$HOME/fstab"
sed '/\.a \/ ffs rw/ s/\(rw,\)/\1noatime,softdep/' "/etc/fstab" | grep 1\ 1 >> "$HOME/fstab"
sed '/\.k \/home ffs rw/ s/\(rw\)/\1,noatime,softdep/' "/etc/fstab" | grep home >> "$HOME/fstab"
sed '/\.d \/tmp ffs rw/ s/\(rw\)/\1,noatime,softdep/' "/etc/fstab" | grep tmp >> "$HOME/fstab"
sed '/\.f \/usr ffs rw/ s/\(rw\)/\1,noatime,softdep/' "/etc/fstab" | grep \/usr\  >> "$HOME/fstab"
sed '/\.g \/usr\/X11R6 ffs rw/ s/\(rw\)/\1,noatime,softdep/' "/etc/fstab" | grep X11R6 >> "$HOME/fstab"
sed '/\.h \/usr\/local ffs rw/ s/\(rw\)/\1,noatime,softdep/' "/etc/fstab" | grep local >> "$HOME/fstab"
sed '/\.j \/usr\/obj ffs rw/ s/\(rw\)/\1,noatime,softdep/' "/etc/fstab" | grep obj >> "$HOME/fstab"
sed '/\.i \/usr\/src ffs rw/ s/\(rw\)/\1,noatime,softdep/' "/etc/fstab" | grep src >> "$HOME/fstab"
sed '/\.e \/var ffs rw/ s/\(rw\)/\1,noatime,softdep/' "/etc/fstab" | grep var >> "$HOME/fstab"

doas cp $HOME/fstab /etc/fstab
