#iNotify Example
Exmaple of the iNotify c API on the standard ubuntu dostrinution.  Shows registering a listener on three events.  

##iDependencies
c compiler, make 

## Build
make

## examples
```
make
touch WatchMe.txt
./iNotifyExample  WatchMe.txt
echo "Hello" WatchMe.txt
touch WatchMe.txt
rm WatchMe.txt
```
