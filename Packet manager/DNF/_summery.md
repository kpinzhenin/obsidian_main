Стандартный менеджер в Fedora, пришедший на смену Yum.
если ссылку не найду:
https://docs.fedoraproject.org/en-US/quick-docs/dnf/

```bash
 $ dnf search <packagename> # поиск пакета
```
```bash
$ sudo dnf install <packagename> # установка пакета
```
```bash
$ sudo dnf remove packagename # удаление пакета
```
Как я понял DNF отвечает только за системные пакеты ( ядро, драйвер ). Для установки повседневных приложений используется другие пакетные менеджеры.
```bash
dnf list installed | grep git # проверяет список установленных приложений
```