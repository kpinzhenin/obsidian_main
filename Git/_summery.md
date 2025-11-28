Создание нового репозитория производится командой 
``` bash
git init
```
Далее нужно указать имя пользователя и почту - нужно для удаленной синхронизации.
``` bash
git config --global user.name "Uset Name"
git config --global user.mail "mail"
```
разделяется на три "места хранения" с несколькими состояниями:
 - Рабочий каталог (working directory)
 - Индекс ( Staged Area ) / Кэш ( Cached )
 - ( Commited )
Индексирование (`cached`/ `staged`) - отслеживание изменений производимых в файле.

Если версии локального и удаленного репозитория отличаются, необходимо:
- синхронизировать их через `git` [[fetch]] `<remote_rep> <remote_branch>`
- после перейти на ветку main ( ту в которую будем сливать изменения) `git` [[checkout]] `main`
- и слить ветки `git` [[Git/merge]] `<remote_rep/branch>

удалить файлы из удаленного репозитория:
	```
	git rm --cached package-lock.json
	git commit
	```

