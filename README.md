# HW18
Сохранение и загрузка в файлы на линуксе + права

1. Реализован makefile. Можно сделать простую сборку (make) или сразу с установкой (make install). При установке происходит сборка проекта, если он еще не был собран, создается рабочая папка /programm (опционально можно поменять на любую другу папку в makefile) и папка /programm/data (если запускать без install, то папка /data создается программой) для хранения файлов данных.
2. Файлы данных создаются при первом запуске программы с суффиксом содержащим имя пользователя (у каждого пользователя будут свои индивидуальные файлы). При создании файлов задаются права rw- --- ---, сделовательно другие пользователи не имеют доступа к файлам других пользователей.
3. Далее программа загружает в vector<User>\vector<Message> данные, если они были записаны на предыдущих запусках и выводит их в консоль.
4. Далее предлагается записать нового пользователя (ключ '1') или новое сообщение (ключ '2') с сохранением в файл для последующих запусков программы и загрузок. Для выхода нужно ввести ключ q. 
