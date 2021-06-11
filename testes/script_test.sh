
# CLONE YOUR PROJECT
cd ~
git clone https://github.com/MarcusVinix/get_next_line.git gnl
cd gnl
norminette *.c *.h

git clone https://github.com/saarikoski-jules/gnl_unit_tests.git
chmod 777 */*.sh

# RUN gnl_unit_tests
cd gnl_unit_tests
sed -i '' "s/PATH_GNL=\"..\/get_next_line\"/PATH_GNL=../" run_tests.sh
sh run_tests.sh
cd ..

# CLEANUP
cd ..
rm -rf gnl