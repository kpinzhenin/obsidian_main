$(pkg-config gobject-2.0 --cflags --libs)
Первое, что нужно запомнить - "соглашение о построение имен"
	В `GObject` имя состоит из двух частей - `Namespace` and `Name`, оба начинаются с Заглавной буквы. Для примера:
	 - GObject это имя Object в пространтве имен G
	 - GtkWidget это имя Widget в пространстве имен Gtk

Процесс создания потомка класса `GObject` :
1. Регистрация нового типа в `системе типов`
	 Регистрация класса производится функцией [[g_type_register_static ()]] которая возращает структуру типа `GType` - которая возвраащется при вызове функции `<namespace name>_<name>_get_type()` которая будте обернута в макрос `<NAMESPACE NAME>_TYPE_NAME ()`. 
	Cамый примичательный это аргумент функции [[GTypeInfo]]. Структура должна быть созданна перед "регистрацией"
2. `Система типов` выделяет память для "собственного" класса и экземпляра класса. По сути это делает функция `g_type_register_static(G_TYPE_OBJECT, "<Name space><Name>, *GTypenfo, 0 )`. Выделяемая память описывается в структуре типа GTypeInfo.
3. Инициализация Класса. объявление функции `<namespace name>_<name>_class_init( <Namespace name><Name>Class *class )`
4. Инициализация экземпляра класса. `<namespace name>_<name>_init (<Namespace name><Name> *self )`

Весь вышеописанный процесс упрощается макросом `G_DEFINE_TYPE(<Name space><Name>, <name_space>_<name>, G_TYPE_OBJECT)`. 	
	Макрос применяется после опеределения:
	 -  структуры класса`_<Namespace name><Name>Class` псевдонимом `<Namespace name><Name>Class`. Не нужно в случае объявления DERIVABLE класса макросом `G_DECLARE_DERIVABLE_TYPE`
	 - структуры экземпляра класса `_<Namespace name><Name>` псевдонимом `<NameSpace><Name>`

Для определения законченного типа ( который не будет порождать производные типы ) используется макрос `G_DECLARE_FINAL_TYPE`.
	При этом все равно нужно объявлять макрос для "получения типа" и структуру, опичывающую "потомка класса". Порядок вызовы следующий:
	  - `#define <Namespace name>_TYPE_<name> (<namespace name>_<name>_get_type() )`
	  - `G_DECLARE_FINAL_TYPE (<Namespace name><Name>, <namespace name>_<name>, <NAMESPACE_NAME>, <NAME>, GObject )`
	  - `struct _<Namespace name><Name> { GObject parent; <self type field name>; }`
	  - `G_DEFINE_TYPE ( <Namespace name><Name>, <namespace name>_<name>, G_TYPE_OBJECT )`
	  - определение функции инициализации класса `static void <spacename name>_<name>_class_init ( <Spacename name><Name>Class *class )`
	  - определение функции инициализации экземпляра класса `static void <spacename name>_<name>_init ( <Spacename name><Name> *self )`
	При этом макрос объявляет:
	  - функцию `<spacename name>_<name>_get_type()` именно объявляет, не определяет
	  - псевдоним структуры `<Spacename name><Name>` как `_<Space name><Name>`. Так же только объявление. Определение структуры `_<Space name><Name>` нужно реализовать.
	  - макрос `<SPACENAME_NAME>_<NAME>()` приведения типа `obj` к `<Spacename><Name>`
	  - макрос `<SPACENAME NAME_IS_<NAME>()` проверяет является ли `obj` экземпляром класса `<Spacename name>`
	  - определение класса `_<Spacename name><Name>Class`

GObject instance is created with `g_object_new` function. GObject has not only instances but also classes (подразумевается, что память под объект класса выделяется при первом вызове). однако `g_object_new` возвращает указатель только на сам экземпляр класса, но не на сам класс.
- A class of GObject is created at the first call of `g_object_new`. And there exists only one GObject class.
- GObject instance is created whenever `g_object_new` is called. So, two or more GObject instances can exist.
`g_object_unref` decreases the reference count by 1. If the reference count drops to zero, the instance destroys itself.
GObject type is a static type (в отличие от динамического класса, который уеичтожается, когда уничтожается последний потомок класса). Static type never destroys its class. So, even if the destroyed instance is the last instance, the class still remains.

Определение наследника класса GObject базируется на макросе `G_DEFINE_TYPE`, который объявляет функции инициализации будущего `класса` и `экземпляра` и функцию которая регистрацию типа как GType и производит:
 - `<name space>_<name>_class_init()`
 - `<name space>_<name>_init()`
 - `<name space>_<name>_get_type()`
