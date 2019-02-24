/* 
 * iNotifyEcample - example of the iNotify API to watch for file activity
 */
#include <stdio.h>  
#include <stdlib.h>  
#include <sys/inotify.h>  
#include <sys/errno.h>  


#define SZ_EVENT  (sizeof (struct inotify_event))
#define SZ_BUF (1024 * (SZ_EVENT + 16))
#define ERROR -1
#define OK 0

main(int argc, char** argv)
{
	// initialise and error check.
	int iEvents=0;
	int fd = inotify_init ();
	if (fd < OK)
	{
        	perror ("inotify_init");
		exit (ERROR);
	}

	// watch and error check
	int wd = inotify_add_watch (fd,   
		    		argv[1], 
				IN_MODIFY | IN_CREATE | IN_DELETE);
	if (wd < OK)
	{
		perror ("inotify_add_watch");
		exit (ERROR);
	}

	char buf[SZ_BUF];
	int len, i = 0;

	while(1){
		len = read (fd, buf, SZ_BUF);
		if (len < 0) {
			if (errno == EINTR)
				perror("...read returned -ve value");
			else
				perror ("read");
		} else if (!len){
			/* SZ_BUF too small? */
		} else {
			iEvents = len/SZ_EVENT;
			printf("Got %d events\n", iEvents);
		}

		for (i = 0; i<= iEvents; i++) {
			struct inotify_event *event;

			event = (struct inotify_event *) &buf[i];
			printf ("wd=%d mask=%u cookie=%u len=%u\n",
				event->wd, event->mask,
				event->cookie, event->len);

			if (event->len)
				printf ("name=%s\n", event->name);

			i += SZ_EVENT + event->len;
		}
	}

}
