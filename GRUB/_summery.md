GRUB - Grand Unified Bootloader.
В GRUB принято свое соглашение имен относящихся к жесткому диску.
```bash
hd0, msdos1 # Hard disk number 0 and partition number 1, which has an MS-DOS partition table
hd2, gpt1 # Hard disk number 3 and partition number 1, which has a GPT partition table
hd0, 0 # Hard disk number 0 and partition number 1
```
В GRUB нумерация жестких дисков начинаются с 0, а разделов с 1.

GRUB хранит свои файлы в разных папках системы ( и это *третья* часть загрузчика, хранящаяся в разделе с установленной операционной системой ):
 - /boot/grub2/
 - /etc/default/grub
 - /etc/grub.d/
 
 /boot/grub2/ - содержит основные файлы ядра grub:
	 grub.cfg - включает в себя настройки, где хранятся образы ядра ОС ( /boot/vmlinuz-<version> ) и /boot/initramfs-<version>.
	 device.map 

 /etc/default/grub - содержит косметические настройки отображения и изменения командной строки вносимые пользователем.
 
 /etc/grub.d/ содержит набора скриптов которые выполняются при запуске 