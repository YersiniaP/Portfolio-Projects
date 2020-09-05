--Data Manipulation quieries for Zookeeping Database
--Group 32: Sarah Leon and Samuel Schneider
--Project Step 4 Draft

--queries for getting data
--get all exhibits on allexhibits.html
SELECT exhibit_name, max_species, exhibit_size FROM `exhibits`;
--get exhibit information when searching by exhibit name
SELECT exhibit_name, max_species, exhibit_size FROM `exhibits` WHERE exhibit_name = :input_exhibit_name;

--get all species on allspecies.html
SELECT species_name, number_exhibit, wild_population FROM `species`;
--get species information when searching by species name
SELECT species_name, number_exhibit, wild_population FROM `species` WHERE species_name = :input_species_name;

--get all animals on allanimals.html
SELECT animal_name, exhibit_home, species_type FROM `animals`;
--get all animal information when searching by species name
SELECT animal_name, exhibit_home, species_type FROM `animals` WHERE species_type = :input_species;
--get all animal information when searching by exhibit name
SELECT animal_name, exhibit_home, species_type FROM `animals` WHERE exhibit_home = :input_exhibit;

--queries for creating data
--add new zookeeper
INSERT INTO zookeepers (keeper_name, exhibit_count, keeper_total) VALUES
	(:input_keeper_name, :input_exhibit_count, :input_keeper_total);

--add new exhibit
INSERT INTO exhibits (exhibit_name, max_species, exhibit_size) VALUES (:input_exhibit_name, :input_max_species, :input_exhibit_size)

--add new species
INSERT INTO species(species_name, number_exhibit, wild_population) VALUES (:input_species_name, :input_number_exhibit, :inputwild_population);

--add new animal
INSERT INTO animals(animal_name, species_type, exhibit_home) VALUES (:input_animal_name, :input_species_type, :input_exhibit_home);

--queries for updating data
--updating zookeepers data
UPDATE zookeeper SET keeper_name = :input_keeper_name, exhibit_count = :input_exhibit_count, keeper_total = :input_keeper_total;

--updating exhibit data
UPDATE exhibits SET exhibit_name = :input_exhibit_name, max_species = :input_max_species, exhibit_size = :input_exhibit_size;

--updating animal data
UPDATE animals SET animal_name = :input_animal_name, exhibit_home = :input_exhibit_home;

--queries for deleting data
--deleting a zookeeper
DELETE FROM zookeepers WHERE keeper_name = :input_keeper_name;

--deleting an animal
DELETE FROM animals WHERE animal_name = :input_animal_name;