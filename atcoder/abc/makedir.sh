for i in {1..103}
do
  id=`printf %03d $i`
  echo "mkdir ${id}"
  echo `mkdir ${id}`
done
