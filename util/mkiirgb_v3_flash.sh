sudo mount -t drvfs $1: /mnt/$1 -o uid=$(id -u $USER),gid=$(id -g $USER),metadata
rm /mnt/$1/FLASH.BIN
cp /home/ryul/qmk_firmware/.build/kbdfans_kbd67_mkiirgb_v3_al7ech.bin /mnt/$1/FLASH.BIN
sudo umount /mnt/$1