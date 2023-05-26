# Тестовое задание Piklema
____
Проект является реализацией тестового задания для фирсы piklema

## TODO
____
1. [x] Вывод сообщений из приложения
2. [x] Парсинг файла
3. [x] Парсинг только численных строк
4. [x] Лок Run
5. [x] Линтер Clang Tidy
6. [ ] Unit tests
7. [x] Linux + Windows + ArmMac build
8. [x] Mqtt build from source lib

## Инструкция по запуску

___

1. Склонировать проект
    ```
        git clone https://github.com/Mentalsupernova/PiklemaMqttTest
    ```
2. Собрать из исходников Mqtt для QT6.5
    ```
   mkdir ~/temporal && cd ~/temporal
   git clone https://github.com/qt/qtmqtt.git

   cd qtmqtt
   git checkout 6.5.0
   mkdir build && cd build
   qt-configure-module ..
   
   cmake --build .

   cmake --install . --verbose
   ```
3. Собрать проект
   ```
   cd PiklemaMqttTest
   mkdir build
   cd build
   cmake ..
   make 
   ```
4. Запустить
    ``` 
   ./PiklemaMqttTest 
   ```

## Линтер
```
   clang-tidy <name_of file>
```

