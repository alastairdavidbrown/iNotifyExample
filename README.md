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
echo "Hello" > WatchMe.txt 	# Event caught
touch WatchMe.txt		# Event not caught
rm WatchMe.txt			# Ecent caught
```
