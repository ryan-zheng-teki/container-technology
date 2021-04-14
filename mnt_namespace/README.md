##This tutorial is from here.
https://www.redhat.com/sysadmin/mount-namespaces
How to create a separate mount namespace, and change the new mount as root.

export CONTAINER_ROOT_FOLDER=/container_practice

mkdir -p ${CONTAINER_ROOT_FOLDER}/fakeroot
chown -R container-user:container-user . 

cd ${CONTAINER_ROOT_FOLDER}

wget https://dl-cdn.alpinelinux.org/alpine/v3.13/releases/x86_64/alpine-minirootfs-3.13.1-x86_64.tar.gz

###create user and group
sudo useradd container-user

##create user namespace and mount namespace
unshare --user --mount  --map-root-user bash --norc


##bind mount a directory
export CONTAINER_ROOT_FOLDER=/container_practice
mount --bind ${CONTAINER_ROOT_FOLDER}/fakeroot ${CONTAINER_ROOT_FOLDER}/fakeroot
cd ${CONTAINER_ROOT_FOLDER}/fakeroot