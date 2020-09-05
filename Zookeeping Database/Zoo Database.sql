SET FOREIGN_KEY_CHECKS = 0;
DROP TABLE IF EXISTS zookeepers;
DROP TABLE IF EXISTS exhibits;
DROP TABLE IF EXISTS species;
DROP TABLE IF EXISTS animals;
DROP TABLE IF EXISTS zookeepers_exhibits;
SET FOREIGN_KEY_CHECKS = 1;

CREATE TABLE zookeepers (
`keeper_id` int(11) NOT NULL AUTO_INCREMENT,
`keeper_name` varchar(255),
`max_exhibits` int(2) DEFAULT '1',
`keeper_total` int(3) DEFAULT '0',
PRIMARY KEY (`keeper_id`),
UNIQUE KEY `keeper_name` (`keeper_name`)
);

CREATE TABLE exhibits (
`exhibit_id` int(11) NOT NULL AUTO_INCREMENT,
`exhibit_name` varchar(255) NOT NULL,
`max_species` int(1) DEFAULT '1',
`exhibit_size` int(4) DEFAULT '0',
PRIMARY KEY (`exhibit_id`),
UNIQUE KEY `exhibit_name` (`exhibit_name`)
);

CREATE TABLE species (
    species_id int(11) AUTO_INCREMENT,
    species_name varchar(255) NOT NULL UNIQUE,
    species_location varchar(255),
    wild_population int(11) DEFAULT '0',
    PRIMARY KEY(species_id),
    FOREIGN KEY(species_location)
    	REFERENCES exhibits(exhibit_name)
);

CREATE TABLE animals (
    animal_id int(11) AUTO_INCREMENT NOT NULL,
    animal_name varchar(255) NOT NULL UNIQUE,
    exhibit_home varchar(255),
    species_type varchar(255),
    PRIMARY KEY(animal_id),
    FOREIGN KEY(exhibit_home)
    	REFERENCES exhibits(exhibit_name),
    FOREIGN KEY(species_type)
    	REFERENCES species(species_name)
);

CREATE TABLE zookeepers_exhibits (
    keeper_id int NOT NULL,
    exhibit_id int NOT NULL,
    FOREIGN KEY (keeper_id)
    	REFERENCES zookeepers(keeper_id),
    FOREIGN KEY (exhibit_id)
    	REFERENCES exhibits(exhibit_id)
);

INSERT INTO zookeepers (`keeper_name`,`max_exhibits`, `keeper_total`) VALUES
	('Alfred Pennyworth', 3, 67), ('Andy Dufresne', 2, 90), ('Bill Lumbergh', 2, 53),
    ('Charles Fleming', 1, 93), ('Deanna Troi', 2, 79), ('Ellen Ripley', 2, 83),
    ('Glen Coco', 3, 88), ('Han Solo', 1, 38), ('Jane Goodall', 1, 36),
    ('Jean-Luc Picard', 2, 69), ('Jeffrey Lebowski', 2, 38), ('Joe Blake', 3, 35), 
    ('John McClane', 1, 91), ('Juliana Crain', 1, 45), ('Malcolm Renolds', 1, 75),
    ('Milton Waddams', 3, 39), ('Peter Gibbons', 3, 48), ('River Tam', 1, 43), 
    ('Robert Paulson', 2, 48), ('Samir Nagheenanajar', 2, 53), ('Sarah Connor', 1, 70), 
    ('Regina George', 3, 46), ('Steve Irwin', 3, 37), ('Thomas Anderson', 3, 57),
    ('William Riker', 2, 80)
;

INSERT INTO exhibits (exhibit_name, max_species, exhibit_size) VALUES
	("Serengeti", 8, 39462),
    ("Arctic Circle", 7, 34880),
    ("Temperate Forest", 7, 32582),
    ("Coastal Waters", 5, 20566),
    ("Aviary", 6, 27164),
    ("Prairielands", 12, 59563),
    ("Rainforest", 9, 44204),
    ("Desert", 5, 23033)
;

INSERT INTO species(`species_name`, `species_location`, `wild_population`) VALUES
	("Lion", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Serengeti'), 20000),
    ("Cheetah", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Serengeti'), 7100),
    ("Hornbill", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Serengeti'), 500),
	("Hyena", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Serengeti'), 9500),
    ("Polar Bear", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Arctic Circle'), 26500),
    ("Arctic Fox", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Arctic Circle'), 110000),
    ("Walrus", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Arctic Circle'), 129000),
    ("Caribou", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Arctic Circle'), 2100000),
    ("Black Bear", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Arctic Circle'), 800000),
    ("Bobcat", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Arctic Circle'), 875000),
    ("Coyote", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Prairielands'), 1600000),
    ("Prairie Dog", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Prairielands'), 15000000),
    ("American Bison", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Prairielands'), 15000),
    ("Grouse", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Prairielands'), 350000),
    ("Scorpion", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Desert'), 28000000),
    ("Caracal", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Desert'), 38000),
    ("Fennec Fox", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Desert'), 63000),
    ("Rattlesnake", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Desert'), 122000),
    ("Grey Wolf", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Temperate Forest'), 13500),
    ("Poison Dart Frog", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Rainforest'), 57000),
    ("Anaconda", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Rainforest'), 48000),
    ("Silverback Gorilla", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Rainforest'), 900),
    ("Western Grebe", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Coastal Waters'), 96000),
    ("Great Blue Heron", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Coastal Waters'), 111000),
    ("Sea Otter", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Coastal Waters'), 3000),
    ("Gyrfalcon", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Aviary'), 72000),
    ("Bald Eagle", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Aviary'), 9700),
    ("Kestrel", (SELECT exhibit_name FROM exhibits WHERE exhibit_name = 'Aviary'), 413000)
;

INSERT INTO animals (animal_name, species_type, exhibit_home) VALUES
("Simba", (SELECT species_name FROM `species` WHERE species_name = 'Lion'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')),
("Nala", (SELECT species_name FROM `species` WHERE species_name = 'Lion'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Scar", (SELECT species_name FROM `species` WHERE species_name = 'Lion'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Kiara", (SELECT species_name FROM `species` WHERE species_name = 'Lion'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Matthew", (SELECT species_name FROM `species` WHERE species_name = 'Lion'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("James", (SELECT species_name FROM `species` WHERE species_name = 'Lion'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Reebok", (SELECT species_name FROM `species` WHERE species_name = 'Cheetah'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Cheetara", (SELECT species_name FROM `species` WHERE species_name = 'Cheetah'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Crystal", (SELECT species_name FROM `species` WHERE species_name = 'Cheetah'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Miles", (SELECT species_name FROM `species` WHERE species_name = 'Cheetah'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Rocket", (SELECT species_name FROM `species` WHERE species_name = 'Cheetah'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Ophelia ", (SELECT species_name FROM `species` WHERE species_name = 'Cheetah'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Umlaut", (SELECT species_name FROM `species` WHERE species_name = 'Cheetah'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Zazu", (SELECT species_name FROM `species` WHERE species_name = 'Hornbill'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Rowan", (SELECT species_name FROM `species` WHERE species_name = 'Hornbill'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Henry", (SELECT species_name FROM `species` WHERE species_name = 'Hornbill'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Jayne", (SELECT species_name FROM `species` WHERE species_name = 'Hornbill'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Rickey", (SELECT species_name FROM `species` WHERE species_name = 'Hornbill'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')),
("Zatia ", (SELECT species_name FROM `species` WHERE species_name = 'Hornbill'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Wonka", (SELECT species_name FROM `species` WHERE species_name = 'Hornbill'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Shenzi", (SELECT species_name FROM `species` WHERE species_name = 'Hyena'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Banzai", (SELECT species_name FROM `species` WHERE species_name = 'Hyena'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Ed", (SELECT species_name FROM `species` WHERE species_name = 'Hyena'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Sid", (SELECT species_name FROM `species` WHERE species_name = 'Hyena'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Tilda ", (SELECT species_name FROM `species` WHERE species_name = 'Hyena'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Serengeti')), 
("Kala", (SELECT species_name FROM `species` WHERE species_name = 'Polar Bear'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Marty", (SELECT species_name FROM `species` WHERE species_name = 'Polar Bear'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Carol", (SELECT species_name FROM `species` WHERE species_name = 'Polar Bear'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Indigo", (SELECT species_name FROM `species` WHERE species_name = 'Polar Bear'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Vulpix", (SELECT species_name FROM `species` WHERE species_name = 'Arctic Fox'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Nicholas", (SELECT species_name FROM `species` WHERE species_name = 'Arctic Fox'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Shiloh", (SELECT species_name FROM `species` WHERE species_name = 'Arctic Fox'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Elijah", (SELECT species_name FROM `species` WHERE species_name = 'Arctic Fox'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Casper", (SELECT species_name FROM `species` WHERE species_name = 'Arctic Fox'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Violet", (SELECT species_name FROM `species` WHERE species_name = 'Arctic Fox'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Onassis", (SELECT species_name FROM `species` WHERE species_name = 'Arctic Fox'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Bristles", (SELECT species_name FROM `species` WHERE species_name = 'Walrus'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')),
("Augustus", (SELECT species_name FROM `species` WHERE species_name = 'Walrus'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Dale", (SELECT species_name FROM `species` WHERE species_name = 'Walrus'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Hemingway", (SELECT species_name FROM `species` WHERE species_name = 'Walrus'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Antoinette", (SELECT species_name FROM `species` WHERE species_name = 'Walrus'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Milton", (SELECT species_name FROM `species` WHERE species_name = 'Walrus'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Comet", (SELECT species_name FROM `species` WHERE species_name = 'Caribou'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Blitzen", (SELECT species_name FROM `species` WHERE species_name = 'Caribou'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Donner", (SELECT species_name FROM `species` WHERE species_name = 'Caribou'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Prancer", (SELECT species_name FROM `species` WHERE species_name = 'Caribou'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Dasher", (SELECT species_name FROM `species` WHERE species_name = 'Caribou'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Arctic Circle')), 
("Yogi", (SELECT species_name FROM `species` WHERE species_name = 'Black Bear'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("BooBoo", (SELECT species_name FROM `species` WHERE species_name = 'Black Bear'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Baloo", (SELECT species_name FROM `species` WHERE species_name = 'Black Bear'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Cindy", (SELECT species_name FROM `species` WHERE species_name = 'Black Bear'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Filbert", (SELECT species_name FROM `species` WHERE species_name = 'Black Bear'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Horton", (SELECT species_name FROM `species` WHERE species_name = 'Black Bear'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Robert", (SELECT species_name FROM `species` WHERE species_name = 'Bobcat'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Pounce", (SELECT species_name FROM `species` WHERE species_name = 'Bobcat'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Osborne", (SELECT species_name FROM `species` WHERE species_name = 'Bobcat'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Felix", (SELECT species_name FROM `species` WHERE species_name = 'Bobcat'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Patrick", (SELECT species_name FROM `species` WHERE species_name = 'Bobcat'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Greta", (SELECT species_name FROM `species` WHERE species_name = 'Bobcat'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Samson", (SELECT species_name FROM `species` WHERE species_name = 'Coyote'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Jim", (SELECT species_name FROM `species` WHERE species_name = 'Coyote'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Wiley", (SELECT species_name FROM `species` WHERE species_name = 'Coyote'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Jacob", (SELECT species_name FROM `species` WHERE species_name = 'Coyote'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Nutmeg", (SELECT species_name FROM `species` WHERE species_name = 'Coyote'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Rupert", (SELECT species_name FROM `species` WHERE species_name = 'Coyote'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Gamma", (SELECT species_name FROM `species` WHERE species_name = 'Coyote'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Dakota", (SELECT species_name FROM `species` WHERE species_name = 'Prairie Dog'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Thelma", (SELECT species_name FROM `species` WHERE species_name = 'Prairie Dog'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Andre", (SELECT species_name FROM `species` WHERE species_name = 'Prairie Dog'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Tobias", (SELECT species_name FROM `species` WHERE species_name = 'Prairie Dog'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Harley", (SELECT species_name FROM `species` WHERE species_name = 'Prairie Dog'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Peter", (SELECT species_name FROM `species` WHERE species_name = 'Prairie Dog'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')),
("Keith", (SELECT species_name FROM `species` WHERE species_name = 'Prairie Dog'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Vivian", (SELECT species_name FROM `species` WHERE species_name = 'American Bison'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Morton", (SELECT species_name FROM `species` WHERE species_name = 'American Bison'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Ricardo", (SELECT species_name FROM `species` WHERE species_name = 'American Bison'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Thomas", (SELECT species_name FROM `species` WHERE species_name = 'American Bison'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Colorado", (SELECT species_name FROM `species` WHERE species_name = 'American Bison'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Lars", (SELECT species_name FROM `species` WHERE species_name = 'American Bison'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Mark", (SELECT species_name FROM `species` WHERE species_name = 'American Bison'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Wilson", (SELECT species_name FROM `species` WHERE species_name = 'American Bison'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Brooke", (SELECT species_name FROM `species` WHERE species_name = 'Grouse'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')),
("Ami", (SELECT species_name FROM `species` WHERE species_name = 'Grouse'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')),
("Pepper", (SELECT species_name FROM `species` WHERE species_name = 'Grouse'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')),
("Cynthia", (SELECT species_name FROM `species` WHERE species_name = 'Grouse'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Linnet ", (SELECT species_name FROM `species` WHERE species_name = 'Grouse'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Joy", (SELECT species_name FROM `species` WHERE species_name = 'Grouse'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Prairielands')), 
("Jack", (SELECT species_name FROM `species` WHERE species_name = 'Scorpion'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Marcus", (SELECT species_name FROM `species` WHERE species_name = 'Scorpion'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Louis", (SELECT species_name FROM `species` WHERE species_name = 'Scorpion'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Dusty", (SELECT species_name FROM `species` WHERE species_name = 'Scorpion'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Gilgamesh ", (SELECT species_name FROM `species` WHERE species_name = 'Scorpion'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Feldspar", (SELECT species_name FROM `species` WHERE species_name = 'Scorpion'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Lola", (SELECT species_name FROM `species` WHERE species_name = 'Caracal'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Rose", (SELECT species_name FROM `species` WHERE species_name = 'Caracal'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Amber", (SELECT species_name FROM `species` WHERE species_name = 'Caracal'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Ginger", (SELECT species_name FROM `species` WHERE species_name = 'Caracal'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Sylvester", (SELECT species_name FROM `species` WHERE species_name = 'Caracal'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Korsa", (SELECT species_name FROM `species` WHERE species_name = 'Fennec Fox'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Ryo", (SELECT species_name FROM `species` WHERE species_name = 'Fennec Fox'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Amba", (SELECT species_name FROM `species` WHERE species_name = 'Fennec Fox'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Frank", (SELECT species_name FROM `species` WHERE species_name = 'Fennec Fox'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Andalusia", (SELECT species_name FROM `species` WHERE species_name = 'Fennec Fox'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Pippin", (SELECT species_name FROM `species` WHERE species_name = 'Fennec Fox'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Alexander", (SELECT species_name FROM `species` WHERE species_name = 'Fennec Fox'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')),
("Rei", (SELECT species_name FROM `species` WHERE species_name = 'Rattlesnake'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')),
("Olivia", (SELECT species_name FROM `species` WHERE species_name = 'Rattlesnake'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("George", (SELECT species_name FROM `species` WHERE species_name = 'Rattlesnake'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Tennessee", (SELECT species_name FROM `species` WHERE species_name = 'Rattlesnake'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')),
("Franz ", (SELECT species_name FROM `species` WHERE species_name = 'Rattlesnake'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Chomper", (SELECT species_name FROM `species` WHERE species_name = 'Rattlesnake'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Desert')), 
("Victoria", (SELECT species_name FROM `species` WHERE species_name = 'Grey Wolf'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Noah", (SELECT species_name FROM `species` WHERE species_name = 'Grey Wolf'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Linus", (SELECT species_name FROM `species` WHERE species_name = 'Grey Wolf'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Rooney", (SELECT species_name FROM `species` WHERE species_name = 'Grey Wolf'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Bandit", (SELECT species_name FROM `species` WHERE species_name = 'Grey Wolf'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Lucius", (SELECT species_name FROM `species` WHERE species_name = 'Grey Wolf'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Opal", (SELECT species_name FROM `species` WHERE species_name = 'Grey Wolf'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Kathryn", (SELECT species_name FROM `species` WHERE species_name = 'Grey Wolf'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Remus", (SELECT species_name FROM `species` WHERE species_name = 'Grey Wolf'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Temperate Forest')), 
("Spike", (SELECT species_name FROM `species` WHERE species_name = 'Poison Dart Frog'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Karen", (SELECT species_name FROM `species` WHERE species_name = 'Poison Dart Frog'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Sena", (SELECT species_name FROM `species` WHERE species_name = 'Poison Dart Frog'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Johnny", (SELECT species_name FROM `species` WHERE species_name = 'Poison Dart Frog'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Genoa", (SELECT species_name FROM `species` WHERE species_name = 'Poison Dart Frog'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')),
("Neptune", (SELECT species_name FROM `species` WHERE species_name = 'Poison Dart Frog'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Astro", (SELECT species_name FROM `species` WHERE species_name = 'Poison Dart Frog'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Zoi", (SELECT species_name FROM `species` WHERE species_name = 'Anaconda'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Jade", (SELECT species_name FROM `species` WHERE species_name = 'Anaconda'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Gaia", (SELECT species_name FROM `species` WHERE species_name = 'Anaconda'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Pierce", (SELECT species_name FROM `species` WHERE species_name = 'Anaconda'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Snakey", (SELECT species_name FROM `species` WHERE species_name = 'Anaconda'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Emerald ", (SELECT species_name FROM `species` WHERE species_name = 'Anaconda'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Loni", (SELECT species_name FROM `species` WHERE species_name = 'Anaconda'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Maria", (SELECT species_name FROM `species` WHERE species_name = 'Silverback Gorilla'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Rala", (SELECT species_name FROM `species` WHERE species_name = 'Silverback Gorilla'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Citrine", (SELECT species_name FROM `species` WHERE species_name = 'Silverback Gorilla'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Clementine", (SELECT species_name FROM `species` WHERE species_name = 'Silverback Gorilla'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Cleo", (SELECT species_name FROM `species` WHERE species_name = 'Silverback Gorilla'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Gibbons", (SELECT species_name FROM `species` WHERE species_name = 'Silverback Gorilla'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Darth ", (SELECT species_name FROM `species` WHERE species_name = 'Silverback Gorilla'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Pamela ", (SELECT species_name FROM `species` WHERE species_name = 'Silverback Gorilla'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Rainforest')), 
("Margaret", (SELECT species_name FROM `species` WHERE species_name = 'Western Grebe'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Beryl", (SELECT species_name FROM `species` WHERE species_name = 'Western Grebe'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Cooper", (SELECT species_name FROM `species` WHERE species_name = 'Western Grebe'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Angelo", (SELECT species_name FROM `species` WHERE species_name = 'Western Grebe'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Ruby ", (SELECT species_name FROM `species` WHERE species_name = 'Western Grebe'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Jet", (SELECT species_name FROM `species` WHERE species_name = 'Western Grebe'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Ezekiel ", (SELECT species_name FROM `species` WHERE species_name = 'Western Grebe'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')),
("Naru", (SELECT species_name FROM `species` WHERE species_name = 'Great Blue Heron'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Bonnie", (SELECT species_name FROM `species` WHERE species_name = 'Great Blue Heron'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Antonovka ", (SELECT species_name FROM `species` WHERE species_name = 'Great Blue Heron'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Medlocke", (SELECT species_name FROM `species` WHERE species_name = 'Great Blue Heron'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Rossington", (SELECT species_name FROM `species` WHERE species_name = 'Great Blue Heron'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Eddie", (SELECT species_name FROM `species` WHERE species_name = 'Sea Otter'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Charm", (SELECT species_name FROM `species` WHERE species_name = 'Sea Otter'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Ruth", (SELECT species_name FROM `species` WHERE species_name = 'Sea Otter'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Wednesday ", (SELECT species_name FROM `species` WHERE species_name = 'Sea Otter'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Isabella", (SELECT species_name FROM `species` WHERE species_name = 'Sea Otter'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Anita", (SELECT species_name FROM `species` WHERE species_name = 'Sea Otter'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Coastal Waters')), 
("Juno", (SELECT species_name FROM `species` WHERE species_name = 'Gyrfalcon'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Pearl", (SELECT species_name FROM `species` WHERE species_name = 'Gyrfalcon'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Cloud", (SELECT species_name FROM `species` WHERE species_name = 'Gyrfalcon'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Aspen", (SELECT species_name FROM `species` WHERE species_name = 'Gyrfalcon'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Saxon", (SELECT species_name FROM `species` WHERE species_name = 'Gyrfalcon'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Angelica ", (SELECT species_name FROM `species` WHERE species_name = 'Gyrfalcon'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Zeta", (SELECT species_name FROM `species` WHERE species_name = 'Gyrfalcon'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Thunder", (SELECT species_name FROM `species` WHERE species_name = 'Bald Eagle'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Christoph", (SELECT species_name FROM `species` WHERE species_name = 'Bald Eagle'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Optimus", (SELECT species_name FROM `species` WHERE species_name = 'Bald Eagle'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Bolt", (SELECT species_name FROM `species` WHERE species_name = 'Bald Eagle'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Admiral ", (SELECT species_name FROM `species` WHERE species_name = 'Bald Eagle'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Venus", (SELECT species_name FROM `species` WHERE species_name = 'Bald Eagle'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Maslow", (SELECT species_name FROM `species` WHERE species_name = 'Kestrel'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Myrtle", (SELECT species_name FROM `species` WHERE species_name = 'Kestrel'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Ferris", (SELECT species_name FROM `species` WHERE species_name = 'Kestrel'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Penny", (SELECT species_name FROM `species` WHERE species_name = 'Kestrel'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Avery", (SELECT species_name FROM `species` WHERE species_name = 'Kestrel'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Liz", (SELECT species_name FROM `species` WHERE species_name = 'Kestrel'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary')), 
("Gale", (SELECT species_name FROM `species` WHERE species_name = 'Kestrel'), (SELECT exhibit_name FROM `exhibits` WHERE exhibit_name = 'Aviary'));

INSERT INTO zookeepers_exhibits (keeper_id, exhibit_id) VALUES
	(1, 7), (1, 4), (1, 8), 
    (2, 4), (2, 7), 
    (3, 7), (3, 2), 
    (4, 8), (5, 3), (6, 1),
    (7, 7), (7, 6), 
    (8, 3), (9, 8), (10, 2), (11, 6),
    (12, 2), (12, 6),
    (13, 2), (14, 2), (15, 5), 
    (16, 8), (16, 1),
    (17, 6), (17, 2), 
    (18, 1), (19, 8), 
    (20, 2), (20, 1),
    (21, 7), 
    (22, 4), (22, 1), (22, 5),
    (23, 3), (23, 5), (23, 7), 
    (24, 4), (24, 5), (24, 7),
    (25, 3), (25, 7)
;