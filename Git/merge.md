Объединяет commit'ы как между собой ? так и между ветками. Объединение происходит на стороне "активной" на текущий момент ветки.
```bash
git merge <branch_name>
git merge <commit_num>
git merge -X theirs feature # Сливаем feature в main конфликты в пользу feature
```
для того, чтобы по-файлово обозначить файлы применяется команда `checkout` следующим образом:
```bash
git checkout --theirs -- <file_name> # Берет версию файла из сливаемой ветки В СЛУЧАЕ КОНФЛИКТА
git checkout <branch_name> -- <file_name>  #Берет версию файла из ветки всегда
```