
# Проєкт: Шифрування Цезаря
**Автора:** Ангеліна Кошелєва

## Опис проєкту
Цей проєкт реалізує алгоритм шифрування та дешифрування Цезаря в рамках завдання з дисципліни "Принципи та парадигми мов програмування" (PLPP).
Проєкт складається з виконуваного файлу та DLL бібліотеки, яка містить функції для шифрування і дешифрування тексту за допомогою алгоритму Цезаря.

## Функціонал
Програма дозволяє:
1. **Шифрування тексту**: Перетворює введений текст, зміщуючи кожну літеру в алфавіті на задану кількість позицій (ключ).
2. **Дешифрування тексту**: Відновлює оригінальний текст із зашифрованого, застосовуючи зворотне зміщення за тим самим ключем.
3. **Збереження регістру та спеціальних символів**: Шифрування та дешифрування застосовуються лише до літер (A-Z, a-z), зберігаючи регістр та залишаючи без змін пробіли, знаки пунктуації тощо.
4. **Обробка помилок**: Перевіряє, чи не є вхідний текст порожнім, та видає відповідне повідомлення у разі помилки.

## Структура проєкту
- **ceasar.h**: Заголовковий файл, який містить прототипи функцій `encrypt` та `decrypt` з модифікатором `extern "C"` для сумісності з іншими мовами програмування.
- **ceasar.cpp**: Містить реалізацію функцій:
  - `char* encrypt(char* rawText, int key)`: Шифрує текст, зміщуючи літери на задану кількість позицій.
  - `char* decrypt(char* encryptedText, int key)`: Дешифрує текст, виконуючи зворотне зміщення.
- **main.cpp**: Виконуваний файл, який демонструє роботу функцій шифрування та дешифрування на 3-х прикладах текст з ключем через динамічне завантаження DLL.
- **CMakeLists.txt**: Файл для збирання проєкту за допомогою CMake, який визначає стандарт C++20 та компілює всі необхідні файли.

## Як працює програма
1. Користувач задає текст (наприклад, "Hello World!") та ключ шифрування (наприклад, 3).
2. Функція `encrypt` зміщує кожну літеру в тексті на 3 позиції вперед в алфавіті (наприклад, 'H' → 'K', 'e' → 'i'), зберігаючи регістр та спеціальні символи.
3. Результат шифрування виводиться на екран.
4. Функція `decrypt` застосовується до зашифрованого тексту, зміщуючи літери на 3 позиції назад, щоб відновити оригінальний текст.
5. Результат дешифрування виводиться на екран.
6. Пам’ять, виділена для зашифрованого та дешифрованого тексту, коректно звільняється.

## Тестування
![image](https://github.com/user-attachments/assets/3e0e19ab-4431-406d-9210-f97c07325c41)
![image](https://github.com/user-attachments/assets/092236b2-26fc-482f-8b74-fc9fa4a7e8b4)

