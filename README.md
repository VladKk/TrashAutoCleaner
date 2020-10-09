# TrashAutoCleaner

Simple daemon which regularly clears trash bin

## How To Use

1) Build the source code with CMake
2) **First launch must be as superuser!** (to create link in /etc/init.d)
3) Use keys:
    * -b: to break the daemon before execution
    * -*n*: where *n* - number of minutes between trash bin clearing
    * -ss: clear trash bin only once and stop daemon
4) In order to stop the daemon, enter
    ```
    ps -eo 'tty,pid,comm' | grep ^?
    ```   
    to find TrashAutoCleaner PID and use 
    ```
    kill -9 *PID_here*
    ```
    to stop the daemon
    
## Built With

* [CMake](https://cmake.org/) - served to build the project

## Contributing

If you have suggestions, write: 
* GMail: **vladislav.kolyadenko@gmail.com**
* Telegram: **@vlad_is_real** 
* Instagram: **@ncks_gwc**

## Versioning

For the versions available, see the [TrashAutoCleaner](https://github.com/VladKk/TrashAutoCleaner). 

## Authors

* **Vladislav Kolyadenko** - *Main developer* - [VladKk](https://github.com/VladKk)

## Acknowledgments

* I only learn programming and the project may have a lot of bugs and mistakes, so don't judge strictly:)
* The program was developed and tested on Ubuntu and I don't know how it works on other systems