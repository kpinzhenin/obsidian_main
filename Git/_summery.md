Если версии локального и удаленного репозитория отличаются, необходимо синхронизировать их через 
`git` [[fitch]] <remote_rep> <remote_branch>

после перейти на ветку main ( ту в которую будем сливать изменеия)
`git` [[checkout]] main

и слить ветки
`git` [[merge]] <remote_rep/branch>

удалить файлы удаленного репозитория:
	```
	git rm --cached package-lock.json
	git commit
	```

