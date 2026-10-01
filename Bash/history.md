выводит история последних набранных команд, если указать параметр n - то выведется n последних команд. Как оказалось отлично работает с символом `!`:
```bash
$ history 10
  567  type history
  568  history
  569  git status
  570  git add Bash/_summery.md
  571  git add Bash/history.md
  572  git commit -m "+bash"
  573  git push git_rep
  574  history 3
  575  history 5
  576  history 10
$ !569 
git status

```