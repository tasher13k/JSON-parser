# JSON-parser
4-th semester course work

Описание:
Простейший интерпретатор для алгоритмов, записанных в формате JSON

Сборка: 
1 Собрать библиотеку cparse, используя инструкцию внутри папкм cparse
2 Для самого проекта написал CMakeList, который линкует объектные файлы библиотеки с кодом проекта

Детальное описание:
Данный интерпретатор получает на вход json файл, в котором находится список (в квадратных скобках) команд, каждая из которых представленна тоже списком. 
Разрешены 4 вида команд:
1 - создать переменную с указанным именем
2 - задать значение переменной
3 - поставить метку в данной точке
4 - перейти по метке при условия неравенства нулю значения переменной
