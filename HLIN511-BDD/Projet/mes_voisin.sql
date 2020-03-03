-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le :  mer. 13 nov. 2019 à 09:04
-- Version du serveur :  5.7.26
-- Version de PHP :  7.2.18

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `mes_voisin`
--

-- --------------------------------------------------------

--
-- Structure de la table `service`
--

DROP TABLE IF EXISTS `service`;
CREATE TABLE IF NOT EXISTS `service` (
  `idservice` int(3) NOT NULL,
  `libelle` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`idservice`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `service`
--

INSERT INTO `service` (`idservice`, `libelle`) VALUES
(1, 'babysitting'),
(2, 'peinture'),
(3, 'menuiserie');

-- --------------------------------------------------------

--
-- Structure de la table `travail`
--

DROP TABLE IF EXISTS `travail`;
CREATE TABLE IF NOT EXISTS `travail` (
  `idvois` int(3) NOT NULL,
  `idserv` int(3) NOT NULL,
  `dateservice` date NOT NULL,
  `prix` int(3) DEFAULT NULL,
  PRIMARY KEY (`idvois`,`idserv`,`dateservice`),
  KEY `idserv` (`idserv`),
  KEY `dateservice` (`dateservice`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `travail`
--

INSERT INTO `travail` (`idvois`, `idserv`, `dateservice`, `prix`) VALUES
(1, 1, '2018-01-01', 50),
(2, 2, '2018-01-02', 60),
(3, 1, '2018-01-03', 70),
(3, 1, '2018-01-04', 200),
(2, 1, '2018-11-21', 40),
(1, 3, '2018-01-08', 15),
(1, 2, '2018-09-18', 45);

-- --------------------------------------------------------

--
-- Structure de la table `voisin`
--

DROP TABLE IF EXISTS `voisin`;
CREATE TABLE IF NOT EXISTS `voisin` (
  `idvoisin` int(3) NOT NULL,
  `nom` varchar(10) NOT NULL,
  `prenom` varchar(10) DEFAULT NULL,
  `ville` varchar(15) DEFAULT NULL,
  `rue` varchar(20) DEFAULT NULL,
  `codepostal` int(5) DEFAULT NULL,
  PRIMARY KEY (`idvoisin`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `voisin`
--

INSERT INTO `voisin` (`idvoisin`, `nom`, `prenom`, `ville`, `rue`, `codepostal`) VALUES
(1, 'dupond', 'pierre', 'montpellier', 'saint priest', 34090),
(2, 'dupond', 'pierre', 'montpellier', 'saint priest', 34090),
(3, 'durand', 'paul', 'montpellier', 'foch', 34091);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
