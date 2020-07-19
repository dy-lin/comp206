#!/bin/bash
cd ~ #Discussion board said that using relative path was okay!!

if test $1 #check if there was a $1 argument, if a name was provided at all
then
	if test $2 #check if a $2 was given, if given, invalid name (project name must be one word)
	then
		echo "Project name given is invalid. No white spaces or characters are allowed."
	else
		name=$1 #store the command line $1 in case it gets overwritten 

		curr_dir="project"
		if test ! -d $curr_dir
		then 
			mkdir $curr_dir
		fi
			cd $curr_dir

		curr_dir="cs206"

		if test ! -d $curr_dir
		then 
			mkdir $curr_dir
		fi
			cd $curr_dir

		curr_dir=$name

		if test -d $curr_dir
		then 
			echo "This project name has already been used."
			exit
		else 
			mkdir $curr_dir
			cd $curr_dir
			mkdir "archive" 
			mkdir "backup"
			mkdir "docs" 
			mkdir "assets" 
			mkdir "database"
			mkdir "source"
		fi 
			curr_dir="source"
			cd $curr_dir
			echo "#!/bin/bash" > backup.sh
			echo "cp *.[ch] ../backup" >> backup.sh
			echo "echo "Your files have been successfully backed up."" >> backup.sh
		chmod +rx backup.sh
		echo "Your project directories have been created."
	fi
else
	echo "You have not entered a project name."
fi