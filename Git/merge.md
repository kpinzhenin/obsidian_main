Объединяет commit'ы как между собой ? так и между ветками. Объединение происходит на стороне "активной" на текущий момент ветки.
```bash
git merge <branch_name>
git merge <commit_num>
git merge -X theirs feature # Сливаем feature в main конфликты в пользу feature
```