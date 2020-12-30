for dir in */; do
   cd $dir
   make -s clean
   cd ..
done
