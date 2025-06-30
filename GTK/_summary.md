GTK не является одним инструментом, скорее это объединение нескольких библиотек, отвечающих за реализацию различного функционала GTK.
#### User interface and display[](https://www.gtk.org/docs/apis/#user-interface-and-display)
- [GTK](https://docs.gtk.org/gtk4/) — Widget toolkit for graphical interfaces
- [GDK](https://docs.gtk.org/gdk4/) — Low-level abstraction for the windowing system
- [GSK](https://docs.gtk.org/gsk4/) — Low-level scene graph and 3D rendering API
- [Pango](https://docs.gtk.org/Pango/) — International text rendering with full Unicode support
- [Cairo](https://www.cairographics.org/manual/) — 2D, vector-based drawing for high-quality graphics
- [ATK](https://docs.gtk.org/atk/) — Accessibility toolkit to implement support for screen readers and other tools (GTK3 only
 
Они оказывается бывают разных версий, последняя - GTK4.
Однако есть GTK2. и по ней есть неплохая вроде как книга:

*Глава 16 из книги “Нейл Мэтью, Ричард Стоунс — Основы программирования в Linux, 4-е издание, пер. с англ.”. _Материал переработан под GTK+ 3. https://librebay.github.io/index.html

Реализация библиотеки основана на библиотеках [[Cu/extend_libraries/GLib/_summery]] и [[GObject]]

Внутренние "сигналы" GTK никакого отношения к сигналам UNIX([[POSIX_Signals]]) не имеют отношения. Это внутрення система событий и приемников событий.

вот такая модель наследования используется в GTK
```
GObject
╰── GInitiallyUnowned
    ╰── GtkWidget
        ╰── GtkContainer
            ╰── GtkBin
                ╰── GtkWindow
```
