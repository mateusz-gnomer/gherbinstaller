#!/bin/bash
#script to create test tree dir with mock files

rm -r -f $1/data
mkdir $1/data
mkdir $1/data/Meshes
touch $1/data/Meshes/uninteresting_file.nif
touch $1/data/Meshes/FLORA_no_picked.nif

mkdir $1/data/Meshes/o
touch $1/data/Meshes/o/Flora_Black_Anther_01.nif
touch $1/data/Meshes/o/flora_plant_03.NIF
touch $1/data/Meshes/o/Flora_mock.nif
echo "original" > $1/data/Meshes/o/Flora_mock.nif

touch $1/data/Meshes/o/Flora_Black_Anther_02.nif
touch $1/data/Meshes/o/Flora_BM_holly_01.nif

mkdir $1/data/Meshes/GHerb
touch $1/data/Meshes/GHerb/Black_Anther_02_P.nif
touch $1/data/Meshes/GHerb/mock_U.nif
echo "unpicked_gh" > $1/data/Meshes/GHerb/mock_U.nif

touch $1/data/Meshes/GHerb/Black_Anther_01_P.nif
echo "picked_plant" > $1/data/Meshes/GHerb/Black_Anther_01_P.nif

mkdir $1/data/Meshes/GHerb/t
touch $1/data/Meshes/GHerb/t/plant_03_P.NIF

mkdir $1/data/Meshes/GHerb/b
touch $1/data/Meshes/GHerb/b/BM_holly_01_P.nif

mkdir $1/data/Meshes/GHerb/m
touch $1/data/Meshes/GHerb/m/no_unpicked_P.nif

