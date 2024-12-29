### 1. Базовые конструкции

#### (a) Алфавит языка. Ключевые слова. Идентификаторы. Литералы. Знаки операций.
- **Алфавит языка:** состоит из букв латинского алфавита (A-Z, a-z), цифр (0-9), символов подчеркивания (_), пробелов и специальных символов.
- **Ключевые слова:** зарезервированные слова, например, `int`, `return`, `if`, `else`, `while`, `for`, `switch`, `case`, `default`, `break`, `continue`, `class`, `public`, `private`, `protected`, `static`, `const`, `virtual`, `override`, `final`, и т.д.
- **Идентификаторы:** пользовательские имена для переменных, функций, классов и т.д. Должны начинаться с буквы или символа подчеркивания, и могут содержать буквы, цифры и символ подчеркивания.
- **Литералы:** константные значения, например, числовые (`42`, `3.14`), символьные (`'a'`), строковые (`"hello"`), логические (`true`, `false`).
- **Знаки операций:** операторы, например, арифметические (`+`, `-`, `*`, `/`, `%`), логические (`&&`, `||`, `!`), сравнения (`==`, `!=`, `<`, `>`, `<=`, `>=`), побитовые (`&`, `|`, `^`, `~`, `<<`, `>>`), присваивания (`=`, `+=`, `-=`, `*=`, `/=`, `%=`).

#### (b) Структура программы на C++. Объявления и определения. Операторы. Комментарии.
- **Структура программы:** включает директивы препроцессора (#include), объявления и определения функций и переменных, основной блок программы (`int main() {}`).
- **Объявления и определения:** Объявление сообщает компилятору о существовании идентификатора (например, `extern int x;`), а определение выделяет память (например, `int x = 5;`).
- **Операторы:** инструкции, выполняющие действия (например, присваивание, арифметические операции, условные выражения).
- **Комментарии:** однострочные (`//`) и многострочные (`/* ... */`).

#### (c) Концепция типа данных. Фундаментальные типы данных: целые типы, символьный тип, логический тип, типы с плавающей точкой, void. Операции над фундаментальными типами.
- **Концепция типа данных:** Тип данных определяет множество значений и операции, которые могут быть выполнены с этими значениями.
- **Фундаментальные типы данных:**
    - **Целые типы:** `int`, `short`, `long`, `long long`, их знаковые и беззнаковые варианты (`signed`, `unsigned`).
    - **Символьный тип:** `char`, `wchar_t`, `char16_t`, `char32_t`.
    - **Логический тип:** `bool`.
    - **Типы с плавающей точкой:** `float`, `double`, `long double`.
    - **void:** специальный тип для указания на отсутствие типа.
- **Операции над фундаментальными типами:** арифметические операции, операции сравнения, логические операции, побитовые операции.

#### (d) Переменные. Классы памяти и области действия. Область видимости. Инициализация. CV-квалификаторы.
- **Переменные:** именованные области памяти для хранения данных.
- **Классы памяти:** `automatic` (локальные переменные), `static` (статические переменные), `dynamic` (динамически выделенная память), `thread_local`.
- **Область действия:** блок кода, в пределах которого переменная доступна.
- **Инициализация:** присваивание начального значения переменной (например, `int x = 0;`).
- **CV-квалификаторы:** `const` (константность), `volatile` (предотвращение оптимизаций).

#### (e) Выражения. Особенности работы операций. Категории значения. static_cast, sizeof.
- **Выражения:** комбинации переменных, литералов и операторов, которые вычисляются в значение (например, `a + b`).
- **Особенности работы операций:** приоритет и ассоциативность операций.
- **Категории значения:** lvalue (объект, к которому можно получить адрес), rvalue (значение, к которому нельзя получить адрес).
- **static_cast:** явное приведение типов.
- **sizeof:** оператор для получения размера типа или объекта в байтах (например, `sizeof(int)`).

### 2. Операторы управления

#### (a) Условная операция (?:). Условный оператор (if-else).
- **Условная операция (?:):** тернарный оператор, который возвращает одно из двух значений в зависимости от условия (например, `int x = (a > b) ? a : b;`).
- **Условный оператор (if-else):** позволяет выполнять блок кода в зависимости от условия (например, `if (a > b) { /* код */ } else { /* код */ }`).

#### (b) Циклы: while, do-while, for.
- **while:** выполняет блок кода, пока условие истинно (например, `while (x < 10) { x++; }`).
- **do-while:** выполняет блок кода хотя бы один раз, затем повторяет выполнение, пока условие истинно (например, `do { x++; } while (x < 10);`).
- **for:** выполняет блок кода определенное количество раз (например, `for (int i = 0; i < 10; i++) { /* код */ }`).

#### (c) Оператор switch.
- **switch:** позволяет выполнить одну из нескольких возможных ветвей кода в зависимости от значения выражения (например, `switch (x) { case 1: /* код */ break; case 2: /* код */ break; default: /* код */ }`).

#### (d) Операторы break и continue. Оператор безусловного перехода.
- **break:** завершает выполнение ближайшего внешнего цикла или оператора switch.
- **continue:** пропускает оставшуюся часть текущей итерации цикла и переходит к следующей итерации.
- **Оператор безусловного перехода:** `goto`, который позволяет передать управление к указанной метке в пределах функции (например, `goto label;` ... `label: /* код */`).

### 3. Массивы и указатели

#### (a) Операция взятия адреса. Указатели. Разыменовывание указателя. Арифметика указателей. Константные указатели и указатели на константы. Нулевой указатель. Провисший указатель.
- **Операция взятия адреса:** `&` оператор для получения адреса переменной (например, `int *p = &x;`).
- **Указатели:** переменные, хранящие адреса других переменных (например, `int *p;`).
- **Разыменовывание указателя:** `*` оператор для доступа к значению по адресу, хранящемуся в указателе (например, `int y = *p;`).
- **Арифметика указателей:** операции с указателями (например, `p++`, `p + 1`, `p - 1`).
- **Константные указатели и указатели на константы:** указатели, адреса которых нельзя изменить, и указатели, указывающие на неизменяемые значения.
- **Нулевой указатель:** указатель, не указывающий ни на какой объект (например, `nullptr`).
- **Провисший указатель:** указатель, указывающий на освобожденную область памяти.

#### (b) Ссылки. Правила работы со ссылками. Ссылки на константу.
- **Ссылки:** алиасы для других переменных (например, `int &ref = x;`).
- **Правила работы со ссылками:** ссылки должны быть инициализированы при объявлении и не могут быть перенаправлены.
- **Ссылки на константу:** ссылки, указывающие на неизменяемые значения (например, `const int &ref = x;`).

#### (c) Массивы в стиле C. Операции над массивами. Инициализация массивов. Связь массивов и указателей. Указатель на массив. Многомерные массивы.
- **Массивы в стиле C:** фиксированные наборы однотипных элементов (например, `int arr[10];`).
- **Операции над массивами:** доступ к элементам массива, итерация по массиву.
- **Инициализация массивов:** присваивание начальных значений элементам массива (например, `int arr[3] = {1, 2, 3};`).
- **Связь массивов и указателей:** имя массива является указателем на его первый элемент.
- **Указатель на массив:** указатель, указывающий на весь массив (например, `int (*p)[10] = &arr;`).
- **Многомерные массивы:** массивы массивов (например, `int matrix[3][3];`).

#### (d) Динамическая память. Выражения new и delete. Динамические массивы.
- **Динамическая память:** память, выделяемая и освобождаемая во время выполнения программы с помощью `new` и `delete` (например, `int *p = new int; delete p;`).
- **Динамические массивы:** массивы, создаваемые и удаляемые во время выполнения программы (например, `int *arr = new int[10]; delete[] arr;`).

#### (e) Строковые литералы. Строки в стиле C. Функции для работы со строками (<cstring>).
- **Строковые литералы:** последовательности символов, заключенные в двойные кавычки (например, `"hello"`).
- **Строки в стиле C:** массивы символов, оканчивающиеся нулевым символом (`\0`).
- **Функции для работы со строками:** функции библиотеки `<cstring>` для манипуляции строками (например, `strcpy`, `strlen`, `strcmp`).

### 4. Функции

#### (a) Функции. Объявление и определение. Возвращаемое значение, аргументы, аргументы по умолчанию.
- **Функции:** блоки кода, выполняющие определенную задачу.
- **Объявление и определение:** Объявление функции сообщает компилятору о её существовании, а определение содержит код функции (например, `int sum(int a, int b);` и `int sum(int a, int b) { return a + b; }`).
- **Возвращаемое значение:** тип данных, который возвращает функция (например, `int`).
- **Аргументы:** входные данные функции (например, `(int a, int b)`).
- **Аргументы по умолчанию:** аргументы с заданными значениями по умолчанию (например, `void func(int a = 10);`).

#### (b) Перегрузка функций. Статические переменные функции.
- **Перегрузка функций:** создание нескольких функций с одинаковым именем, но разными параметрами (например, `int sum(int a, int b);` и `double sum(double a, double b);`).
- **Статические переменные функции:** переменные, сохраняющие своё значение между вызовами функции (например, `static int count = 0;`).

#### (c) Передача и возврат указателей, ссылок и массивов в/из функции.
- **Передача указателей:** позволяет функции изменять значения переменных, на которые указывают указатели (например, `void func(int *p);`).
- **Передача ссылок:** позволяет функции изменять значения аргументов, переданных по ссылке (например, `void func(int &ref);`).
- **Передача массивов:** передача указателя на первый элемент массива (например, `void func(int arr[]);`).
- **Возврат указателей, ссылок и массивов:** возврат указателей и ссылок из функций (например, `int* func();`).

#### (d) Рекурсия: прямая, косвенная. Примеры рекурсивных вычислений.
- **Прямая рекурсия:** функция вызывает сама себя (например, вычисление факториала).
- **Косвенная рекурсия:** функция вызывает другую функцию, которая в свою очередь вызывает первую (например, `void A() { B(); } void B() { A(); }`).
- **Примеры рекурсивных вычислений:** вычисление факториала, числа Фибоначчи.

### 5. Пользовательские типы

#### (a) Перечисления (enum)
- **Перечисления:** пользовательский тип данных, состоящий из набора именованных констант (например, `enum Color { RED, GREEN, BLUE };`).

#### (b) Объединения (union)
- **Объединения:** пользовательский тип данных, позволяющий хранить разные типы данных в одной и той же области памяти (например, `union Data { int i; float f; };`).

#### (c) Структуры (struct)
- **Структуры:** пользовательский тип данных, позволяющий объединять данные разных типов (например, `struct Point { int x; int y; };`).

### 6. Шаблоны

#### (a) Шаблоны функций. Шаблоны классов. Шаблоны переменных. Шаблоны псевдонимов типов (using).
- **Шаблоны функций:** позволяют создавать функции, работающие с разными типами данных (например, `template <typename T> T sum(T a, T b);`).
- **Шаблоны классов:** позволяют создавать классы, работающие с разными типами данных (например, `template <typename T> class Array;`).
- **Шаблоны переменных:** позволяют создавать переменные шаблонов (например, `template <typename T> T value;`).
- **Шаблоны псевдонимов типов:** позволяют создавать псевдонимы типов (например, `template <typename T> using Ptr = T*;`).

#### (b) Вывод типа аргумента шаблона. Параметры шаблона по умолчанию. Перегрузка шаблонов функций. Объявление auto переменных.
- **Вывод типа аргумента шаблона:** автоматическое определение типа аргумента шаблона на основе переданного значения (например, `auto x = sum(1, 2);`).
- **Параметры шаблона по умолчанию:** задание значений по умолчанию для параметров шаблона (например, `template <typename T = int> class Array;`).
- **Перегрузка шаблонов функций:** создание нескольких шаблонных функций с одинаковым именем, но разными параметрами (например, `template <typename T> T sum(T a, T b); template <typename T> T sum(T a, T b, T c);`).
- **Объявление auto переменных:** использование ключевого слова `auto` для автоматического определения типа переменной (например, `auto x = 5;`).

#### (c) Специализация шаблонов. Инстанцирование шаблонов.
- **Специализация шаблонов:** создание специализированных версий шаблонов для определенных типов данных (например, `template <> class Array<char>;`).
- **Инстанцирование шаблонов:** создание конкретных экземпляров шаблонов (например, `Array<int> arr;`).

### 7. Классы. Начало

#### (a) Парадигмы программирования. Объектно-ориентированное программирование. Абстракция, инкапсуляция, полиморфизм, наследование.
- **Парадигмы программирования:** различные подходы к программированию (например, процедурное, объектно-ориентированное, функциональное).
- **Объектно-ориентированное программирование:** парадигма, основанная на объектах и классах.
    - **Абстракция:** выделение значимых характеристик объекта, исключая незначимые.
    - **Инкапсуляция:** сокрытие внутренней реализации объекта и предоставление интерфейса для взаимодействия с ним.
    - **Полиморфизм:** способность объектов различных классов реагировать на одни и те же сообщения по-разному.
    - **Наследование:** создание нового класса на основе существующего с добавлением новых или изменением существующих характеристик.

#### (b) Классы и объекты. Поля и методы. Модификаторы доступа. Друзья класса.
- **Классы и объекты:** классы определяют структуру и поведение объектов.
- **Поля и методы:** поля — переменные класса, методы — функции класса.
- **Модификаторы доступа:** определяют уровень доступа к полям и методам (`public`, `private`, `protected`).
- **Друзья класса:** функции или классы, имеющие доступ к приватным и защищенным членам класса (например, `friend class B;`).

#### (c) Константные и статические поля и методы. Логическая и физическая константность. Ключевое слово mutable.
- **Константные поля и методы:** не изменяют состояния объекта (`const`).
- **Статические поля и методы:** принадлежат классу, а не экземпляру класса (`static`).
- **Логическая и физическая константность:** логическая константность — не изменяет логическое состояние объекта, физическая — не изменяет его физическое состояние.
- **Ключевое слово mutable:** позволяет изменять поля в константных методах.

### 8. Конструкторы и деструктор

#### (a) Агрегатная инициализация. Конструктор. Виды конструкторов. Списки инициализации. Делегирующие конструкторы. Ключевое слово explicit.
- **Агрегатная инициализация:** инициализация объектов с помощью списка инициализаторов (например, `Point p = {1, 2};`).
- **Конструктор:** специальная функция, вызываемая при создании объекта.
    - **Виды конструкторов:** конструктор по умолчанию, параметризованный конструктор, конструктор копирования.
- **Списки инициализации:** список инициализации полей в конструкторе (например, `Point(int x, int y) : x(x), y(y) {}`).
- **Делегирующие конструкторы:** конструкторы, вызывающие другие конструкторы (например, `Point() : Point(0, 0) {}`).
- **Ключевое слово explicit:** предотвращает неявное преобразование типов при вызове конструктора.

#### (b) Конструкции = default и = delete.
- **Конструкции = default и = delete:** позволяют явно указывать, что конструктор или метод должны быть автоматически сгенерированы компилятором или удалены (например, `Point() = default; Point(const Point&) = delete;`).

#### (c) Деструктор. Идиома RAII. Порядок вызова конструкторов и деструкторов. Правило трех.
- **Деструктор:** специальная функция, вызываемая при удалении объекта (например, `~Point();`).
- **Идиома RAII (Resource Acquisition Is Initialization):** управление ресурсами через объекты, которые захватывают ресурсы в своих конструкторах и освобождают в деструкторах.
- **Порядок вызова конструкторов и деструкторов:** сначала вызываются конструкторы базовых классов, затем производных. При уничтожении объекта порядок обратный.
- **Правило трех:** если класс требует явного определения конструктора копирования, оператора присваивания и деструктора, следует определить все три.

### 9. Сборка программ на C++ и перегрузка операций

#### (a) Перегрузка операций. Правила перегрузки операций. Перегрузка побитового сдвига для потокового ввода/вывода.
- **Перегрузка операций:** позволяет определять новые версии операторов для пользовательских типов (например, `Point operator+(const Point& lhs, const Point& rhs);`).
- **Правила перегрузки операций:** некоторые операторы не могут быть перегружены (например, `.` и `.*`).
- **Перегрузка побитового сдвига для потокового ввода/вывода:** перегрузка операторов `<<` и `>>` для работы с потоками (например, `std::ostream& operator<<(std::ostream& os, const Point& p);`).

#### (b) One Definition Rule. Директива #include, проблема двойного включения, стражи включения.
- **One Definition Rule (ODR):** правило, гласящее, что в программе может быть только одно определение каждой функции или переменной.
- **Директива #include:** вставка содержимого одного файла в другой (например, `#include <iostream>`).
- **Проблема двойного включения:** включение одного и того же файла несколько раз, что может вызвать ошибки.
- **Стражи включения:** предотвращение двойного включения с помощью препроцессорных директив (например, `#ifndef HEADER_H #define HEADER_H ... #endif`).

#### (c) Сборка программ на C++. Раздельная компиляция, модули (до C++20). Встраиваемые функции и переменные. Внутреннее и внешнее связывание (static, extern).
- **Сборка программ на C++:** процесс компиляции и линковки, создающий исполняемый файл.
- **Раздельная компиляция:** компиляция отдельных файлов независимо друг от друга.
- **Модули (до C++20):** единицы компиляции, определяющие интерфейс и реализацию.
- **Встраиваемые функции и переменные:** функции и переменные, определенные с ключевым словом `inline`.
- **Внутреннее и внешнее связывание:** управление областью видимости и временем жизни переменных и функций (`static` для внутреннего связывания, `extern` для внешнего).

#### (d) Пространства имен, директивы using и using namespace.
- **Пространства имен:** механизм для предотвращения конфликтов имен (например, `namespace myNamespace { ... }`).
- **Директива using:** позволяет использовать имена из пространства имен без полного квалификационного имени (например, `using myNamespace::myFunction;`).
- **Директива using namespace:** делает все имена из пространства имен доступными без полного квалификационного имени (например, `using namespace std;`).

### 10. Функциональные объекты и алгоритмы

#### (a) Функторы. Классы с перегруженной операцией функционального вызова. Лямбда-выражения.
- **Функторы:** объекты, которые можно вызывать как функции (например, класс с перегруженной оператором `()`).
- **Лямбда-выражения:** анонимные функции, которые можно определять прямо в месте использования (например, `[](int x) { return x * x; }`).

#### (b) Алгоритмы. Модифицирующие алгоритмы. Немодифицирующие алгоритмы. Алгоритмы сортировки. Алгоритмы упорядоченных последовательностей. Алгоритмы для работы с пирамидой.
- **Алгоритмы:** функции из библиотеки `<algorithm>`, выполняющие общие операции над контейнерами (например, `std::sort`, `std::for_each`).
- **Модифицирующие алгоритмы:** изменяют содержимое контейнера (например, `std::transform`).
- **Немодифицирующие алгоритмы:** не изменяют содержимое контейнера (например, `std::find`).
- **Алгоритмы сортировки:** сортируют элементы контейнера (например, `std::sort`, `std::stable_sort`).
- **Алгоритмы упорядоченных последовательностей:** работают с отсортированными контейнерами (например, `std::binary_search`, `std::merge`).
- **Алгоритмы для работы с пирамидой:** работают с пирамидальными структурами данных (например, `std::make_heap`, `std::pop_heap`).

### 11. Контейнеры

#### (a) Последовательные контейнеры: std::array, std::vector, std::deque, std::list, std::forward_list, std::initializer_list.
- **Последовательные контейнеры:** хранят элементы в определенном порядке.
    - **std::array:** фиксированный массив.
    - **std::vector:** динамический массив.
    - **std::deque:** двусторонняя очередь.
    - **std::list:** двусвязный список.
    - **std::forward_list:** односвязный список.
    - **std::initializer_list:** список инициализаторов.

#### (b) Ассоциативные контейнеры: std::map, std::set. unordered- и multi- версии. Structured bindings.
- **Ассоциативные контейнеры:** хранят элементы в виде пар ключ-значение.
    - **std::map:** отображение, упорядоченное по ключам.
    - **std::set:** множество, упорядоченное по ключам.
    - **unordered- и multi- версии:** неупорядоченные и мультиверсии контейнеров (например, `std::unordered_map`, `std::multiset`).
- **Structured bindings:** механизм, позволяющий распаковывать кортежи и пары в отдельные переменные (например, `auto [key, value] = pair;`).

#### (c) Контейнерные адаптеры: std::stack, std::queue, std::priority_queue.
- **Контейнерные адаптеры:** обеспечивают специфичные интерфейсы для работы с элементами.
    - **std::stack:** стек (LIFO).
    - **std::queue:** очередь (FIFO).
    - **std::priority_queue:** очередь с приоритетом.

### 12. Наследование и Статический полиморфизм

#### (a) Наследование. Модификаторы доступа при наследовании. Конструкторы и деструкторы при наследовании.
- **Наследование:** механизм, позволяющий создавать новые классы на основе существующих.
- **Модификаторы доступа при наследовании:** определяют доступ к базовым классам (`public`, `protected`, `private`).
- **Конструкторы и деструкторы при наследовании:** порядок вызова конструкторов и деструкторов в иерархии наследования.

#### (b) Срезка. Затенение методов базового класса. Работа с производными классами через указатель или ссылку на базовый.
- **Срезка:** потеря данных при присваивании объекта производного класса объекту базового класса.
- **Затенение методов базового класса:** методы базового класса, перекрытые методами производного класса.
- **Работа с производными классами через указатель или ссылку на базовый:** использование полиморфизма для работы с объектами различных классов через единый интерфейс.

### 13. Динамический полиморфизм
Динамический полиморфизм в C++ позволяет объектам вести себя по-разному в зависимости от их типа данных во время выполнения программы. Вот краткое объяснение каждого из ваших запросов:

#### (a) Динамический полиморфизм и виртуальные функции:
- **Виртуальные функции** используются для реализации динамического полиморфизма. Они позволяют переопределить методы в производных классах.
- **Идентификатор `override`** используется для явного указания, что метод переопределяет виртуальную функцию базового класса.
- **Идентификатор `final`** применяется к методам, чтобы предотвратить их дальнейшее переопределение в производных классах.
- **Ковариантные возвращаемые типы** позволяют переопределенной функции в производном классе возвращать тип, который является подтипом возвращаемого типа базового класса⁷.

#### (b) Виртуальный деструктор и связывание:
- **Виртуальный деструктор** гарантирует, что при удалении объекта через указатель на базовый класс вызывается правильный деструктор.
- **Позднее связывание** (или динамическое связывание) используется для виртуальных функций и определяет, какая функция будет вызвана, во время выполнения программы.
- **Раннее связывание** (или статическое связывание) определяется во время компиляции и не может быть изменено.
- **Таблица виртуальных функций** (vtable) используется для поддержки позднего связывания в C++¹⁶.

#### (c) Чисто виртуальные функции и абстрактные классы:
- **Чисто виртуальные функции** объявляются с помощью синтаксиса `= 0` и не имеют реализации в базовом классе.
- Класс, содержащий хотя бы одну чисто виртуальную функцию, называется **абстрактным классом**. Это означает, что нельзя создать экземпляр такого класса напрямую¹³.

### 14. Исключения

#### (a) Исключения
В C++ **исключения** используются для обработки неожиданных ситуаций, которые возникают во время выполнения программы. Ключевое слово `throw` используется для генерации исключения, а блок `catch` — для его перехвата.

```cpp
try {
    // Код, который может генерировать исключение
    throw std::runtime_error("Произошла ошибка");
} catch (const std::exception& e) {
    // Обработка исключения
    std::cerr << "Исключение перехвачено: " << e.what() << '\n';
}
```

#### (b) Статическая спецификация исключений
Статическая спецификация исключений в C++ использует ключевое слово `noexcept`. Это указывает, что функция не будет генерировать исключения. `noexcept` может быть использовано как спецификатор (для всей функции) или условный спецификатор (зависит от условия).

```cpp
void myFunction() noexcept; // Спецификатор
void myFunction() noexcept(true); // Условный спецификатор
```

Исключения в **конструкторах** и **деструкторах** могут привести к серьезным проблемам, таким как утечки ресурсов, если они не обрабатываются должным образом.

#### (c) Гарантии безопасности исключений
Гарантии безопасности исключений в C++ классифицируются на три уровня:
- **No-throw guarantee**: Функция обещает не генерировать исключения.
- **Strong guarantee**: Если во время выполнения функции возникает исключение, состояние программы остается неизменным.
- **Basic guarantee**: В случае исключения, программа остается в валидном состоянии, но его конкретное состояние может измениться.

Иерархия исключений в C++ помогает организовать исключения в структурированной форме, позволяя более точно перехватывать и обрабатывать различные типы ошибок.

```cpp
class MyBaseException : public std::exception { /*...*/ };
class MyDerivedException : public MyBaseException { /*...*/ };
```

Таким образом, можно создать структурированную систему обработки ошибок, которая улучшает читаемость и поддерживаемость кода.

### 15. Итераторы

#### (a) Итераторы и их категории
Итераторы в C++ — это объекты, позволяющие перебирать элементы контейнера. Они аналогичны указателям и поддерживают операции, такие как инкрементирование и разыменование.

**Константные итераторы** (`const_iterator`) предоставляют доступ только для чтения к элементам контейнера⁶.

**Категории итераторов** включают:
- **Input iterators**: Для чтения последовательного доступа.
- **Output iterators**: Для записи последовательного доступа.
- **Forward iterators**: Для чтения и записи с возможностью многократного прохода в одном направлении.
- **Bidirectional iterators**: Как forward, но с возможностью движения в обоих направлениях.
- **Random access iterators**: Поддерживают все операции bidirectional итераторов, а также прямой доступ к элементу.

Класс `std::iterator_traits` предоставляет информацию о свойствах итераторов¹⁹.

**Обобщенные функции для работы с итераторами**:
- `std::advance`: Перемещает итератор на заданное количество позиций.
- `std::next`: Возвращает итератор, смещенный на определенное количество позиций вперед от данного.
- `std::prev`: Возвращает итератор, смещенный на определенное количество позиций назад от данного.
- `std::distance`: Возвращает количество элементов между двумя итераторами.

**Инвалидация итераторов** происходит, когда операции с контейнером делают существующие итераторы недействительными[^10^].

**Range-based for** (`for(auto& value : container)`) позволяет итерировать по всем элементам контейнера.

#### (b) Итераторные адаптеры
Итераторные адаптеры изменяют поведение обычных итераторов:

- **Итераторы вставки** (`std::inserter`, `std::back_inserter`, `std::front_inserter`) создают итераторы, которые вставляют элементы в контейнер при присваивании.
- **Обратные итераторы** (`std::reverse_iterator`) позволяют итерировать контейнер в обратном порядке.
- **Итераторы перемещения** (`std::move_iterator`) преобразуют значения, на которые указывают итераторы, в rvalue-ссылки.
- **Потоковые итераторы** (`std::istream_iterator`, `std::ostream_iterator`) используются для чтения и записи элементов из потоков ввода/вывода¹⁶.

Эти инструменты расширяют возможности работы с итераторами, позволяя более гибко управлять процессами вставки, удаления и доступа к элементам контейнеров.

### 16. Категории значений и конструктор перемещения

#### (a) Категории значений и ссылки
В C++, **lvalue** (locator value) обозначает объекты, которые занимают идентифицируемое место в памяти¹. Примеры lvalue: переменные, элементы массива, имена функций. **rvalue** (read value) обозначает временные объекты, которые не связаны с постоянным местоположением в памяти². Примеры rvalue: литералы, временные объекты, возвращаемые значения функций.

**lvalue-ссылки** (`Type&`) используются для ссылок на lvalue, в то время как **rvalue-ссылки** (`Type&&`) используются для ссылок на rvalue, что позволяет реализовать перемещение ресурсов без копирования⁸.

Перегрузка функций по типу ссылки позволяет функциям иметь одно и то же имя, но различаться по типам принимаемых аргументов, включая lvalue и rvalue ссылки[^10^].

#### (b) Конструктор перемещения и перемещающее присваивание
**Конструктор перемещения** (`Type(Type&&)`) и **оператор перемещающего присваивания** (`Type& operator=(Type&&)`) позволяют "переместить" ресурсы из одного объекта в другой, вместо создания копии¹⁵. Это увеличивает производительность, особенно для классов, которые управляют динамически выделенной памятью.

**Правило пяти** в C++ гласит, что если вы определяете одну из следующих функций, то вам, скорее всего, потребуется определить их все⁴⁷:
1. Деструктор
2. Конструктор копирования
3. Оператор присваивания копированием
4. Конструктор перемещения
5. Оператор присваивания перемещением

Это правило помогает управлять ресурсами корректно, предотвращая утечки памяти и другие проблемы с ресурсами. Если класс управляет ресурсом, который требует "глубокого копирования" или специальной логики перемещения, необходимо явно определить эти функции.

### 17. Семантика перемещения

#### (a) Функция `std::move`
Функция `std::move` в C++ используется для преобразования lvalue (объекты, имеющие идентифицируемое местоположение в памяти) в rvalue (временные объекты), что позволяет "переместить" ресурсы из одного объекта в другой¹⁶. Пример использования:

```cpp
std::string a = "Hello";
std::string b = std::move(a); // 'a' теперь не содержит строку "Hello"
```

#### (b) Функция `std::forward`
Функция `std::forward` используется для "идеальной передачи" (perfect forwarding), позволяя сохранить категорию значения (lvalue или rvalue) при передаче параметров в шаблонные функции[^10^]. Пример использования:

```cpp
template <typename T>
void wrapper(T&& arg) {
    function(std::forward<T>(arg));
}
```

#### (c) Copy Elision и RVO/NRVO
**Copy elision** — это оптимизация, при которой компилятор может исключить создание ненужных временных объектов⁶. **Return Value Optimization (RVO)** и **Named Return Value Optimization (NRVO)** являются частными случаями copy elision, где компилятор может оптимизировать возвращаемое значение функции, чтобы избежать лишнего копирования⁸.

#### (d) Универсальные ссылки и вывод шаблонных параметров
**Универсальные ссылки** (forwarding references) в C++ — это rvalue-ссылки, которые могут связываться как с lvalue, так и с rvalue, в зависимости от контекста¹⁹. Правила вывода шаблонных параметров для универсальных ссылок позволяют компилятору определить, должен ли параметр шаблона быть lvalue- или rvalue-ссылкой¹⁸. Пример использования:

```cpp
template <typename T>
void relay(T&& arg) {
    receiver(std::forward<T>(arg));
}
```

В этом примере, если `relay` вызывается с lvalue, `T` выводится как lvalue-ссылка, и `std::forward` передает ее как lvalue. Если `relay` вызывается с rvalue, `T` выводится как rvalue-ссылка, и `std::forward` передает ее как rvalue, позволяя перемещение.