#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

typedef void (*sig_t) (int);

int
runshell(void)
{
   int status, ret, pid;
   sig_t save_quit;
   sig_t save_int;

   save_quit = signal(SIGQUIT, SIG_IGN);
   save_int  = signal(SIGINT,  SIG_IGN);
   if ((pid = fork()) == -1) {
      signal(SIGQUIT, save_quit);
      signal(SIGINT,  save_int);
      return -1;
   }
   if (pid == 0) {
      signal(SIGQUIT, SIG_DFL);
      signal(SIGINT,  SIG_DFL);

      execl("/bin/sh", "sh", (char*)0);
      _exit(127);
   }

   signal(SIGQUIT, SIG_IGN);
   signal(SIGINT,  SIG_IGN);

   /* wait for child termination*/
   while ((ret = waitpid(pid, &status, 0)) != pid)
		continue;

   signal(SIGQUIT, save_quit);
   signal(SIGINT,  save_int);
   return status;
}
