GRUB - Grand Unified Bootloader.
В GRUB принято свое соглашение имен относящихся к жесткому диску.
```bash
hd0, msdos1 # Hard disk number 0 and partition number 1, which has an MS-DOS partition table
hd2, gpt1 # Hard disk number 3 and partition number 1, which has a GPT partition table
hd0, 0 # Hard disk number 0 and partition number 1
```
В GRUB нумерация жестких дисков начинаются с 0, а разделов с 1.