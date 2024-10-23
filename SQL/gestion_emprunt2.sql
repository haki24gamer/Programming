-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Oct 21, 2024 at 10:04 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `gestion_emprunt2`
--

-- --------------------------------------------------------

--
-- Table structure for table `auteur`
--

CREATE TABLE `auteur` (
  `NumAut` int(11) NOT NULL,
  `NomAut` char(30) DEFAULT NULL,
  `PrenomAut` char(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `auteur`
--

INSERT INTO `auteur` (`NumAut`, `NomAut`, `PrenomAut`) VALUES
(1, 'ALI', 'HACHI'),
(2, 'AHMED', 'SOULEIMAN'),
(3, 'OSMAN', 'ALI');

-- --------------------------------------------------------

--
-- Table structure for table `ecrire`
--

CREATE TABLE `ecrire` (
  `Nidentifiant` int(11) NOT NULL,
  `NumAut` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `ecrire`
--

INSERT INTO `ecrire` (`Nidentifiant`, `NumAut`) VALUES
(1, 2),
(2, 3),
(3, 1),
(4, 2);

-- --------------------------------------------------------

--
-- Table structure for table `exemplaire`
--

CREATE TABLE `exemplaire` (
  `num_exemplaire` int(11) NOT NULL,
  `dateAcquisition` date DEFAULT NULL,
  `etat` char(50) DEFAULT NULL,
  `Nidentifiant` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `exemplaire`
--

INSERT INTO `exemplaire` (`num_exemplaire`, `dateAcquisition`, `etat`, `Nidentifiant`) VALUES
(1, '2001-03-12', 'bonne', 1),
(2, '2006-07-03', 'bonne', 2),
(3, '2000-04-13', 'moyenne', 1),
(4, '1999-05-02', 'bonne', 3);

-- --------------------------------------------------------

--
-- Table structure for table `ouvrage`
--

CREATE TABLE `ouvrage` (
  `Nidentifiant` int(11) NOT NULL,
  `numISBn` char(50) DEFAULT NULL,
  `titreouvrage` char(100) DEFAULT NULL,
  `edition` char(20) DEFAULT NULL,
  `refouvrage` char(60) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `ouvrage`
--

INSERT INTO `ouvrage` (`Nidentifiant`, `numISBn`, `titreouvrage`, `edition`, `refouvrage`) VALUES
(1, 'D3', 'ALI PAPA ET LE 40 VOLEURS', 'hachette', '1234SSD'),
(2, 'D4', 'HISTOIRE DE DJIBOUTI', 'LaNation', 'SDER345'),
(3, 'D5', 'LE COMPTE', 'edition', 'sde345'),
(4, 'D6', 'HISTOIRE DE MON FILS', 'hachette', 'jir678'),
(5, 'D77', 'ECOLE PRIMAIRE', 'edition', '289046'),
(24, 'DFE23', 'MON HISTOIRE', 'LaNation', '1234FGH');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `auteur`
--
ALTER TABLE `auteur`
  ADD PRIMARY KEY (`NumAut`);

--
-- Indexes for table `ecrire`
--
ALTER TABLE `ecrire`
  ADD PRIMARY KEY (`Nidentifiant`,`NumAut`),
  ADD KEY `ecrire_ibfk_1` (`NumAut`);

--
-- Indexes for table `exemplaire`
--
ALTER TABLE `exemplaire`
  ADD PRIMARY KEY (`num_exemplaire`),
  ADD KEY `Nidentifiant` (`Nidentifiant`);

--
-- Indexes for table `ouvrage`
--
ALTER TABLE `ouvrage`
  ADD PRIMARY KEY (`Nidentifiant`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `ecrire`
--
ALTER TABLE `ecrire`
  ADD CONSTRAINT `ecrire_ibfk_1` FOREIGN KEY (`NumAut`) REFERENCES `auteur` (`NumAut`),
  ADD CONSTRAINT `ecrire_ibfk_2` FOREIGN KEY (`Nidentifiant`) REFERENCES `ouvrage` (`Nidentifiant`);

--
-- Constraints for table `exemplaire`
--
ALTER TABLE `exemplaire`
  ADD CONSTRAINT `exemplaire_ibfk_1` FOREIGN KEY (`Nidentifiant`) REFERENCES `ouvrage` (`Nidentifiant`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;






