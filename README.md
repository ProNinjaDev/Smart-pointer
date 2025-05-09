# shared_ptr Implementation

Простенькая реализация `shared_ptr` с подсчётом ссылок. Идея - разобраться с RAII и ручным управлением ресурсами через счетчик

## Особенности

*   **Подсчет ссылок:** Есть специальный счётчик, который увеличивается при копировании и присваивании. Уменьшается в деструкторе
*   **Освобождение ресурса:** Происходит в `cleanup()`, когда счётчик доходит до нуля
*   **Основные операции:**
    1)   Конструктор от сырого указателя (`explicit`, чтобы избежать неявных преобразований)
    2)   Конструктор копирования и оператор присваивания (с проверкой на самоприсваивание)
    3)   Деструктор (`~shared_ptr`)
*   **Доступ к объекту:**
    1)   `operator*()` и `operator->()` для разыменования и доступа к членам
    2)   `explicit operator bool()` для проверки на `nullptr`
*   **nullptr отслеживание:** Проверка на `nullptr` внутри `operator*` и `operator->` с вызовом `std::abort()`

В `main.cpp` — базовые тесты, чтобы проверить основные сценарии жизненного цикла и операторы. 