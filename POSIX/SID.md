Session IDentificator
Идентификатор сессии. Сессия это как-то связано с текущим сеансом терминала и командной оболочки, но по мойму все таки терминала (как tty ).
В рамках одной сессии терминала, все запущенные в нем процессы будут иметь одинаковый SID.
И по ходу, когда будет закрыт терминал, закроются все процессы с таким SID.
