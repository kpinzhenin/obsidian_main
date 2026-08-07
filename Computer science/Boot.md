Загрузка операционной системы начинается с *загрузочного сектора* `boot sector`.
`boot sector` описывается как первые 512 байт на жестком диске, плюс 31KB. В каждом разделе резервируется место ( 512b + 31KB ) под `boot-related information( VBR Volume Boot Record или все таки Virtual Boot Record )` и это не MBR!. MBR как раз одна на весь HDD.
Master boot record( MBR ) = Boot record = Boot sector = Bootloader
Предполагается, что 1 сектор = 512 байт. современный размер сектора походу все таки 4 KB.
Загрузчик ( `bootloader` ) делится на 3 части:
 - bootstrap ( 440 bytes ), DeepSeek называет его *"First-stage bootloader"*
 - bootloader ( 31 KB ) это как я понял и есть `VBR( Volume Boot Record)` каждого раздела
 - Часть ядра операционной системы из состава кода основного раздела
 Оказывается 512 байт связаны с тем, что BIOS не умеет читать дальше первого сектора.
every partition has 512 bytes + 31 KB of space reserved for booting
purposes, and this space is hidden from the user.
