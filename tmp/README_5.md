### Запуск


Конфигурационный файл `.config`. В нем:


 - *`socket_name=`* - имя сокета
 - *`file_path=`*- имя файла


Не могу точно сказать, зачем я включил и имя сокета в конфигурацию ( мне кажется так удобней). Но тем не менее.


Запуск с опцией `-d` создает демон, запуск просто без ключа процесс.


## Описание


Файл читается при создании процесса сервера - т.е. и имя пакета и имя файла. Однако размер файла читается при установке соединения с клиентом.


Таким образом, если поменять название файла после создания процесса сервера, размер вернется от предыдущего файла. Но если размер файла изменится в промежуток времени от создания процесса сервера, до подключения клиента, то сервер вернет изменный (актуальный) размер. Размер возвращается в байтах, как поле структуры `struct stat.st_size`
