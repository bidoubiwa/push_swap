A=$1
# COUCOU = FILE_NAME (ON LINE 4 AND 5)
# BEFORE s/ LINE YOU WANT TO CHANGE
cat coucou | sed -e "14s/int z = [0-9]*/int z = $A/g" > test_coucou
mv test_coucou coucou
