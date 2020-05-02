dirs=`find ./ -maxdepth 1 -type d`
files=`find ./ -maxdepth 1 -type f`

for dir in $dirs
do
  echo $dir
  match=`echo $dir | cut -c 3-`

  #./は全部マッチングするのでスキップ
  if `test ${#match} -eq 0`;
  then
    continue
  fi

  for target in $files
  do
    if [[ $target =~ $match ]] ;
    then
      echo `mv $target $dir`
    fi
  done
done
