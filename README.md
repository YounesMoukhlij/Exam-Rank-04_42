## Exam Rank 04

During the Common Core, before you validate each Cercle, you must pass the exam successfully.

**Holy Graph:**
<img width="1318" alt="Screen Shot 2024-06-09 at 9 17 04 PM" src="https://github.com/YounesMoukhlij/Exam_Rank_04_42/assets/123767564/a22d8237-95a7-439f-ab98-96fea7d87634">

### Subject:

<br>
Assignment name  : microshell
<br>
Expected files   : microshell.c
<br>
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
<br>

--------------------------------------------------------------------------------------

Expected files   : microshell.c
Ecrire un programme qui ressemblant à un executeur de commande shell
- La ligne de commande à exécuter sera passer en argument du programme
- Les exécutables seront appelés avec un chemin relatif ou absolu mais votre programme ne devra pas construire de chemin (en utilisant la variable d environment PATH par exemple)
- Votre programme doit implémenter "|" et ";" comme dans bash
	- Nous n'essaierons jamais un "|" immédiatement suivi ou précédé par rien ou un autre "|" ou un ";"
- Votre programme doit implémenter la commande "built-in" cd et seulement avec un chemin en argument (pas de '-' ou sans argument)
	- si cd n'a pas le bon nombre d'argument votre programme devra afficher dans STDERR "error: cd: bad arguments" suivi d'un '\n'
	- si cd a echoué votre programme devra afficher dans STDERR "error: cd: cannot change directory to path_to_change" suivi d'un '\n' avec path_to_change remplacé par l'argument de cd
	- une commande cd ne sera jamais immédiatement précédée ou suivie par un "|"
- Votre programme n'a pas à gérer les "wildcards" (*, ~ etc...)
- Votre programme n'a pas à gérer les variables d'environment ($BLA ...)
- Si un appel système, sauf execve et chdir, retourne une erreur votre programme devra immédiatement afficher dans STDERR "error: fatal" suivi d'un '\n' et sortir
- Si execve échoue votre programme doit afficher dans STDERR "error: cannot execute executable_that_failed" suivi d'un '\n' en ayant remplacé executable_that_failed avec le chemin du programme qui n'a pu etre executé (ça devrait être le premier argument de execve)
- Votre programme devrait pouvoir accepter des centaines de "|" même si la limite du nombre de "fichier ouvert" est inférieur à 30.

Par exemple, la commande suivante doit marcher:
<br>
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
<br>
microshell
<br>
i love my microshell
<br>
$>
<br>

<br>
Conseils:
<br>
N'oubliez pas de passer les variables d'environment à execve
<br>

Conseils:
<br>
Ne fuitez pas de file descriptor!
<br>

<br>
[Contact Me](https://github.com/YounesMoukhlij)
<br>
**Autor: Younes Moukhlij**
