--------------------------------------------------------
--  Fichier cr�� - jeudi-janvier-07-2021   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table PRODUIT
--------------------------------------------------------

  CREATE TABLE "WASSIM"."PRODUIT" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"TYPE" VARCHAR2(20 BYTE), 
	"NOMBRE" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PLANNING
--------------------------------------------------------

  CREATE TABLE "WASSIM"."PLANNING" 
   (	"ID_PLANNING" NUMBER, 
	"NOM_PLANNING" VARCHAR2(20 BYTE), 
	"DATE_PLANNING" VARCHAR2(20 BYTE), 
	"HEURE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FILM
--------------------------------------------------------

  CREATE TABLE "WASSIM"."FILM" 
   (	"ID_FILM" NUMBER, 
	"NOM_FILM" VARCHAR2(20 BYTE), 
	"DATE_SORTIE" VARCHAR2(20 BYTE), 
	"DUREE" VARCHAR2(20 BYTE), 
	"NOTE" NUMBER, 
	"GENRE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table EMPLOYE
--------------------------------------------------------

  CREATE TABLE "WASSIM"."EMPLOYE" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"SALAIRE" NUMBER, 
	"EMAIL" VARCHAR2(20 BYTE), 
	"DATE_NAISSANCE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table CONGE
--------------------------------------------------------

  CREATE TABLE "WASSIM"."CONGE" 
   (	"REF" NUMBER, 
	"DUREE" NUMBER, 
	"DATE_C" DATE, 
	"TYPE" VARCHAR2(20 BYTE), 
	"ID_EMP" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table COMMANDE
--------------------------------------------------------

  CREATE TABLE "WASSIM"."COMMANDE" 
   (	"REFERENCE" NUMBER, 
	"DESCRIPTION" VARCHAR2(30 BYTE), 
	"ETAT" VARCHAR2(20 BYTE), 
	"NOMBRE" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table ABONNEMENT
--------------------------------------------------------

  CREATE TABLE "WASSIM"."ABONNEMENT" 
   (	"NUM" NUMBER, 
	"PRIX" NUMBER, 
	"DUREE" VARCHAR2(20 BYTE), 
	"TYPE" VARCHAR2(20 BYTE), 
	"ID_ABONNEE" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table ABONNEE
--------------------------------------------------------

  CREATE TABLE "WASSIM"."ABONNEE" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"TARIF" VARCHAR2(20 BYTE), 
	"VILLE" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into WASSIM.PRODUIT
SET DEFINE OFF;
Insert into WASSIM.PRODUIT (ID,NOM,TYPE,NOMBRE) values (14,'azaz','azaza',78);
Insert into WASSIM.PRODUIT (ID,NOM,TYPE,NOMBRE) values (144,'az','az',14);
REM INSERTING into WASSIM.PLANNING
SET DEFINE OFF;
Insert into WASSIM.PLANNING (ID_PLANNING,NOM_PLANNING,DATE_PLANNING,HEURE) values (13,'film','08/07/2012','10h');
Insert into WASSIM.PLANNING (ID_PLANNING,NOM_PLANNING,DATE_PLANNING,HEURE) values (1234,'fatmaa','14/12/2021','17h');
Insert into WASSIM.PLANNING (ID_PLANNING,NOM_PLANNING,DATE_PLANNING,HEURE) values (125,'wassim','08/07/2021','16h');
Insert into WASSIM.PLANNING (ID_PLANNING,NOM_PLANNING,DATE_PLANNING,HEURE) values (0,null,null,null);
REM INSERTING into WASSIM.FILM
SET DEFINE OFF;
Insert into WASSIM.FILM (ID_FILM,NOM_FILM,DATE_SORTIE,DUREE,NOTE,GENRE) values (125,'fatma','25/08/2000','100min',9,'romantique');
Insert into WASSIM.FILM (ID_FILM,NOM_FILM,DATE_SORTIE,DUREE,NOTE,GENRE) values (12,'LALAAL','25/08/2017','135min',9,'action');
Insert into WASSIM.FILM (ID_FILM,NOM_FILM,DATE_SORTIE,DUREE,NOTE,GENRE) values (1789,'fatmaa','25/08/2000','140min',4,'horreur');
Insert into WASSIM.FILM (ID_FILM,NOM_FILM,DATE_SORTIE,DUREE,NOTE,GENRE) values (17,'fatmaaa','07/10/2017','200min',9,'action');
Insert into WASSIM.FILM (ID_FILM,NOM_FILM,DATE_SORTIE,DUREE,NOTE,GENRE) values (189,'fatmaaa','18/05/2015','110min',8,'action');
Insert into WASSIM.FILM (ID_FILM,NOM_FILM,DATE_SORTIE,DUREE,NOTE,GENRE) values (0,null,null,null,0,null);
Insert into WASSIM.FILM (ID_FILM,NOM_FILM,DATE_SORTIE,DUREE,NOTE,GENRE) values (1212,null,null,null,0,null);
REM INSERTING into WASSIM.EMPLOYE
SET DEFINE OFF;
Insert into WASSIM.EMPLOYE (ID,NOM,PRENOM,SALAIRE,EMAIL,DATE_NAISSANCE) values (888,null,null,0,null,'01-JAN-00');
Insert into WASSIM.EMPLOYE (ID,NOM,PRENOM,SALAIRE,EMAIL,DATE_NAISSANCE) values (88,null,null,0,null,'01-JAN-00');
Insert into WASSIM.EMPLOYE (ID,NOM,PRENOM,SALAIRE,EMAIL,DATE_NAISSANCE) values (455,null,null,0,null,'01-JAN-00');
Insert into WASSIM.EMPLOYE (ID,NOM,PRENOM,SALAIRE,EMAIL,DATE_NAISSANCE) values (566,null,null,0,null,'01-JAN-00');
Insert into WASSIM.EMPLOYE (ID,NOM,PRENOM,SALAIRE,EMAIL,DATE_NAISSANCE) values (0,null,null,0,null,'01-JAN-00');
Insert into WASSIM.EMPLOYE (ID,NOM,PRENOM,SALAIRE,EMAIL,DATE_NAISSANCE) values (4245,null,null,0,null,'01-JAN-00');
REM INSERTING into WASSIM.CONGE
SET DEFINE OFF;
REM INSERTING into WASSIM.COMMANDE
SET DEFINE OFF;
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (55,null,null,0);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (477,'commande sur le produit cola','livre',78);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (559,'commande sur le produit chips','non livre',24);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (442,'commande sur le produit m&m',' livre',50);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (121,'SSS11','AZAZ',111);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (0,null,null,0);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (99,null,null,0);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (66,null,null,0);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (88,null,null,0);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (994,null,null,0);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (111,null,null,0);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (22,null,null,0);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (122,null,null,0);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (222,null,null,0);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (996,null,null,0);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (888,null,null,0);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (909,null,null,0);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (555,null,null,0);
Insert into WASSIM.COMMANDE (REFERENCE,DESCRIPTION,ETAT,NOMBRE) values (120,null,null,0);
REM INSERTING into WASSIM.ABONNEMENT
SET DEFINE OFF;
Insert into WASSIM.ABONNEMENT (NUM,PRIX,DUREE,TYPE,ID_ABONNEE) values (67,0,null,null,0);
REM INSERTING into WASSIM.ABONNEE
SET DEFINE OFF;
Insert into WASSIM.ABONNEE (ID,NOM,PRENOM,TARIF,VILLE) values (78,'azaz','azazaz','az','azaz');
--------------------------------------------------------
--  DDL for Index PRODUIT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "WASSIM"."PRODUIT_PK" ON "WASSIM"."PRODUIT" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PLANNING_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "WASSIM"."PLANNING_PK" ON "WASSIM"."PLANNING" ("ID_PLANNING") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index FILM_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "WASSIM"."FILM_PK" ON "WASSIM"."FILM" ("ID_FILM") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index EMPLOYE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "WASSIM"."EMPLOYE_PK" ON "WASSIM"."EMPLOYE" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index CONGE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "WASSIM"."CONGE_PK" ON "WASSIM"."CONGE" ("REF") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index COMMANDE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "WASSIM"."COMMANDE_PK" ON "WASSIM"."COMMANDE" ("REFERENCE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index ABONNEMENT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "WASSIM"."ABONNEMENT_PK" ON "WASSIM"."ABONNEMENT" ("NUM") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index ABONNEE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "WASSIM"."ABONNEE_PK" ON "WASSIM"."ABONNEE" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table PRODUIT
--------------------------------------------------------

  ALTER TABLE "WASSIM"."PRODUIT" ADD CONSTRAINT "PRODUIT_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "WASSIM"."PRODUIT" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PLANNING
--------------------------------------------------------

  ALTER TABLE "WASSIM"."PLANNING" ADD CONSTRAINT "PLANNING_PK" PRIMARY KEY ("ID_PLANNING")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "WASSIM"."PLANNING" MODIFY ("ID_PLANNING" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table FILM
--------------------------------------------------------

  ALTER TABLE "WASSIM"."FILM" ADD CONSTRAINT "FILM_PK" PRIMARY KEY ("ID_FILM")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "WASSIM"."FILM" MODIFY ("ID_FILM" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table EMPLOYE
--------------------------------------------------------

  ALTER TABLE "WASSIM"."EMPLOYE" ADD CONSTRAINT "EMPLOYE_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "WASSIM"."EMPLOYE" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table CONGE
--------------------------------------------------------

  ALTER TABLE "WASSIM"."CONGE" ADD CONSTRAINT "CONGE_PK" PRIMARY KEY ("REF")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "WASSIM"."CONGE" MODIFY ("REF" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table COMMANDE
--------------------------------------------------------

  ALTER TABLE "WASSIM"."COMMANDE" ADD CONSTRAINT "COMMANDE_PK" PRIMARY KEY ("REFERENCE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "WASSIM"."COMMANDE" MODIFY ("REFERENCE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table ABONNEMENT
--------------------------------------------------------

  ALTER TABLE "WASSIM"."ABONNEMENT" ADD CONSTRAINT "ABONNEMENT_PK" PRIMARY KEY ("NUM")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "WASSIM"."ABONNEMENT" MODIFY ("NUM" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table ABONNEE
--------------------------------------------------------

  ALTER TABLE "WASSIM"."ABONNEE" ADD CONSTRAINT "ABONNEE_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "WASSIM"."ABONNEE" MODIFY ("ID" NOT NULL ENABLE);