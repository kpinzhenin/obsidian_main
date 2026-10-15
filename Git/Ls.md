У `Git` есть своя реализация утилиты Ls
```bash
git ls-tree <branch_name>
git ls-tree -r <branch_name>          # рекурсивно
git ls-tree <branch_name> --name-only # показвает только имена
```