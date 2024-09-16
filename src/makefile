build-dir=../build
theme=green-icon

all: patch-analytics ${theme}

green-icon:
	mkdir ${build-dir};rsync -avC --progress lab/* themes/${theme}/* ${build-dir}
clean:
	rm -rf ${build-dir}

patch-analytics:
	chmod +x ../scripts/patch-analytics.sh 
	../scripts/patch-analytics.sh
