#!/usr/bin/bash
way=$1
extention=$2
name_folder=$3
name_tar=$4
i=0

if ! [ -d $name_folder ]
then
	mkdir $name_folder
fi

find_and_copy() {
	for files in $1/*
	do
		if [ -f "$files" ]
		then
			local fullfilename=$(basename -- "$files")
			local extent=${fullfilename##*.}
			local filename=${fullfilename%.*}
			if [ "$extent" = "$extention" ]
			then
				local repiate=0
				for names in $(ls "$name_folder")
				do
					if [ "$names" = "$fullfilename" ]
					then
						let repiate++
						cp "$files" "$name_folder/$filename~$i.$extent"
						break
					fi
				done
				if [ $repiate = 0 ]
				then
					cp "$files" "$name_folder/$filename.$extent"
				fi
			fi
			let i++
		elif [ -d "$files" ]
		then
			find_and_copy "$files"
		fi
	done
}

find_and_copy "$way"

tar -cf "$name_tar" "$name_folder"
