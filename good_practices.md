Mes Bonnes Pratiques
====================

Gestion de versions
-------------------

### Général

### Git

### SVN

Convention de codage
--------------------

### Langage C++

#### Règles

  * Longueur des lignes :
Une ligne ne fera pas plus de 82 caractères.

  * Longueur des noms (de variables, de classes, ...) :
Les noms seront le plus explicites possibles.
Le nom sera d'autant plus explicite que la portée de l'objet est grande.
Le nom ne contiendra pas de référence au type de l'objet (pas de notation "hongroise").

  * Indentation :
Le code sera indenté en utilisant 4 espaces.

  * Accolades :
Les accolades seront écrites après un retour à la ligne.
Les accolades sont obligatoires et seront toujours présentes même si elles ne contiennent qu'une seule instruction.

    if (true)
    {
        // something to do...
    }

#### Notations

  * Variable membre privé :

    _ma_variable

  * Variable membre protégé :

    _ma_variable

  * Variable membre public :

    ma_variable

  * Variable locale :

    ma_variable

  * Argument de fonction :

    mon_argument

  * Constante :

    MA_CONSTANTE

  * Enumération :

    enum class MonEnum
    {
        MaValeur
    };

  * Fonction :

    void ma_fonction();

  * Accesseurs :

    // Getter
    Type get_ma_variable() const;
    
    // Setter
    void set_ma_variable(Type new_value);

  * Namespace :

    mon_namespace
    {
    } // mon_namespace


#### Classes et Structures

Les composants de la classe ou de la structure seront rangés de la façon suivante :
  1. Définitions de type
  2. Constantes
  3. Enumérations
  4. Constructeurs
  5. Destructeurs
  6. Accesseurs
  7. Evènements et méthodes déclenchables
  8. Autres méthodes et fonctions
  
Les membres de la classe ou de la structure seront autant que possible privé.

Le mot clé "this" sera utilisé dans l'implémentation de la classe ou de la structure et précédera n'importe quel objet (variable, fonction, enumération, ...) appartenant à la classe ou à la structure.

Une classe ou une structure sera défini dans un seul fichier.

  * Exemple Structure :

    struct MaStructure
    {
        // implémentation
    };

  * Exemple Classe :

    class MaClasse : public MaClasseMere
    {
    public:
        // implementation
        
        MaClasse();
        
        virtual ~MaClasse();
        
        bool get_ma_variable() const;
        
        void set_ma_variable(bool value);
        
        void ma_fonction();
    
    protected:
        // implementation
    
    private:
        // implementation
        
        void _ma_fonction_privee();
        
        bool _ma_variable;
    
    };

#### Fichiers

  * Extensions :
    * Entête : .h
    * Source : .cpp
    * Template : .txx

  * Contenu :
Un fichier contiendra une et une seule classe ou structure.
Le nom du fichier sera identique au nom de la classe ou de la structure qu'il contient.

  * Entête :
Les fichiers d'entête contiennent uniquement les déclarations des classes, des structures et des fonctions.
Les fichiers d'entête contiennent un ”#ifndef” pour se protéger des inclusions multiples.

    // Début du fichier 
    #ifndef <Pattern unique> 
    #define <Pattern unique> 
    
    #endif // <Pattern unique> 
    // fin du fichier 

Pour éviter les inclusions multiples, le pattern sera un GUID préfixé et séparé par “_” (exemple: _8f6a0887_49fa_4f6b_9103_6b4d4768a57b).

#### Commentaires

Documentation
-------------
