# godotCpp
Gdextention to develop in godot with c++

## Before we use the git submodule we always should:
(in this case godot-cpp)
```bash
git rm -r --cached <path-of-the-.git-repo>
```
- Add a submodule
git submodule add <repository-url> <path>

### what the git submodule command does
Git submodules allow you to keep a Git repository as a subdirectory of another Git repository. Git submodules are simply a reference to another repository at a particular snapshot in time. Git submodules enable a Git repository to incorporate and track version history of external code.

it creates at the root of the repository a file called .gitmodules with the settings and definitions of the submodule that we are pushing.
**It practically tells git were to find the submodule repository we mostly use the command below to get the files from the repo itself without cloning it in our repo**

* Git was confused about which repository controlled the godot-cpp files
* You couldn't push because Git saw conflicting version control systems
* The godot-cpp folder contained its own .git directory, creating a "repository within repository" problem

- Initialize submodules after cloning
```bash
git submodule init
git submodule update
```
- Or do both in one command
```bash
git submodule update --init --recursive
```

- Update submodule to latest commit
```bash
git submodule update --remote
```
- Update specific submodule
```bash
git submodule update --remote <submodule-path>
```
- if you clone my repo you need to
git clone <your-repo>
```bash
git submodule update --init --recursive
```
this is to get the **Latest version of godot-cpp that is the library we are working with in order to develop our nodes in godot**

- To update godot-cpp to latest 4.4 branch:
```bash
git submodule update --remote gdextension/godot-cpp
```
- Commit the submodule update:
```bash
git add gdextension/godot-cpp
git commit -m "Update godot-cpp submodule"
```

# My level of knowledge (where i am and what i want to do with this project)
So first of all **I will not abbandon this project** It's a promise i made for a friend and to challenge myself so it's out of question. I know by myself that when the push will be done the notes that the ai gave me will be less rindondant and less at all, and that's a big mistake made by me, that learning with ai is good yes, but done properly I did want to take a shortcut and as a consequence when i came back to keep doing the project i spent 2:30 hours at modifying the readme, this is a lesson for me and for my future self to remember.

So we have the notes down that we can keep as reference (thanks to the ai i have slimmed them a little bit and that's good) but now i need to get a hand on the project mostly i need to keep track of my progess

**progress bar:**
![](https://geps.dev/progress/15)
Not much but it's an honest work.

## The project's milestones
- [x] I'm able to create a class and make it a node to put in godot
- [x] I made at least one game fully in godot before doing this crazy stuff that i'm doing right now that's a free dub because i did it long time ago but, we take those ![](https://preview.redd.it/who-tf-made-this-also-sweaty-eggman-v0-01oq07dtyd8d1.png?width=1080&crop=smart&auto=webp&s=0a8c60d3bfbbc1069af004b844bebabd63b4ed48)
- [ ] I'm able to setup a godot environment to set up the class making or node making in order to develop my own nodes for godot (i kinda forgot how to do it)
- [ ] I know how signal works in godot (I don't do shacks in godot since a year and a half i forgot a lot)
- [ ] I put the "progect jenova™️" to program in cpp instead of gdscript. Take a look at their repo if you want to do that as well https://github.com/Jenova-Framework/J.E.N.O.V.A
- [ ] I know how signals works in the gdextension development
- [ ] I do know how to use the gdextension feature at it's fullest

## How all of this messed up architecture works before starting to code.
sources https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html
**Always read the doc or else** you get most of the time stuck or like me, you forget what you are even doing
I don't cover the prerequisites i will just cover the files that got put into the directory in order to start creating and coding your classes/gdnodes.

*A little parenthesis*:
the doc seems to suggest to you to go deeper by looking at the setting up the editor and the compiling sections, **BUT** the setting up doesn't seem very intuitive _in my humble opinion_ that's because the damn documentation launches you directly on that argument without making you understand how a contribution of the engine works, why you setting your environment for vscode in a certain way and etc... But we are not here for this. We are mostly to understand the compilation with scons and how we manage to use it to add the nodes in the godot project.

**We got to this point next time finish to update the readme with the explanation of how to set up the development environment**

# Generated and slimmed notes

## 1 Gestione del Submodule `godot-cpp`

Per integrare le associazioni (bindings) C++ nel nostro progetto, utilizziamo un sottomodulo Git. Questo permette di mantenere il codice di `godot-cpp` separato ma tracciato all'interno del nostro repository principale.

### Spiegazione del Problema

Inizialmente, Git può essere confuso su quale repository controlli i file di `godot-cpp`, specialmente se la cartella contiene un proprio direttorio `.git`, creando un problema di "repository dentro un repository". I comandi per i sottomoduli risolvono questo problema, trattando `godot-cpp` come una dipendenza esterna.

### Comandi Essenziali per i Submodule

  * **Aggiungere un nuovo submodule:**

    ```bash
    git submodule add <repository-url> <path>
    ```

  * **Clonare un repository che usa submodules:**
    Dopo aver clonato il tuo repository, i sottomoduli non sono ancora presenti. È necessario inizializzarli.

    ```bash
    # Clona il repository principale
    git clone <your-repo>

    # Inizializza e aggiorna ricorsivamente tutti i sottomoduli
    git submodule update --init --recursive
    ```

  * **Aggiornare `godot-cpp` all'ultima versione (es. branch 4.4):**

    ```bash
    # Aggiorna il submodule al commit più recente del suo branch remoto
    git submodule update --remote gdextension/godot-cpp

    # Aggiungi e committa la modifica del submodule nel tuo repository principale
    git add gdextension/godot-cpp
    git commit -m "Update godot-cpp submodule"
    ```

## 2 Concetti Fondamentali di GDExtension

### Che cos'è GDExtension?

GDExtension è un'interfaccia C fornita da Godot Engine. Permette agli sviluppatori di estendere le funzionalità del motore con codice nativo (come C++, Rust, Swift, ecc.) senza dover modificare e ricompilare l'intero codice sorgente di Godot. Le estensioni create vengono caricate dinamicamente dal motore.

I principali casi d'uso includono:

  * Integrare librerie C/C++ di terze parti.
  * Scrivere la logica di gioco critica per le prestazioni in C++.
  * Estendere l'editor di Godot con nuovi nodi o plugin.

### `godot-cpp`: I Binding Ufficiali C++

`godot-cpp` è il repository ufficiale che fornisce i "language bindings" (associazioni di linguaggio) per C++. In pratica, è un wrapper che adatta l'interfaccia C di GDExtension per renderla più idiomatica e facile da usare per uno sviluppatore C++, esponendo l'API di Godot in modo simile a come viene usata internamente dal motore stesso.

### SCons: Il Sistema di Build

SCons è un sistema di build basato su Python utilizzato da Godot e dai progetti GDExtension per gestire il processo di compilazione. Si occupa di compilare sia le librerie di `godot-cpp` sia i nodi personalizzati che crei, rendendoli visibili e utilizzabili dall'engine.

### Il file `.gdextension`

Questo è un file di configurazione essenziale in formato INI che informa Godot su come caricare la tua estensione. Contiene sezioni chiave:

  * **`[configuration]`**: Specifica il punto di ingresso (`entry_symbol`), la compatibilità minima con Godot (`compatibility_minimum`) e se l'estensione supporta l'hot-reloading (`reloadable`).
  * **`[libraries]`**: Elenca i percorsi alle librerie dinamiche (`.dll`, `.so`, `.dylib`) per ogni piattaforma e architettura supportata.
  * **`[dependencies]`**: Elenca eventuali dipendenze da altre librerie.

## 3 Creazione di Classi in C++

### Registrazione della Classe

Perché Godot riconosca una classe C++, sono necessari due elementi chiave nel file sorgente:

  * **`GDCLASS(NomeClasse, ClasseBase)`**: Una macro che gestisce il codice di registrazione interno necessario per integrare la classe nel sistema di tipi di Godot.
  * **`_bind_methods()`**: Una funzione statica protetta che Godot chiama per scoprire quali metodi, proprietà e segnali della classe devono essere esposti al motore, a GDScript e all'editor.

### Allocazione della Memoria: `memnew`

Quando si creano istanze di oggetti che ereditano da `godot::Object`, è **obbligatorio** usare `memnew` invece dell'operatore `new` standard di C++. Godot utilizza un gestore di memoria personalizzato e `memnew` assicura che gli oggetti vengano allocati e inizializzati correttamente, prevenendo crash e memory leak.

### Funzioni del Ciclo di Vita: `_notification` vs `_ready`

Nelle estensioni del motore, è spesso preferibile usare `_notification(NOTIFICATION_READY)` invece del più comune `_ready()`. Questo perché se uno script GDScript viene allegato al tuo nodo nativo, la sua funzione `_ready()` sovrascriverà quella della classe C++. `_notification` non può essere sovrascritto in questo modo, garantendo che il codice di inizializzazione della tua estensione venga sempre eseguito.

### Esporre Proprietà e Segnali

All'interno di `_bind_methods()`, si usano delle macro specifiche per esporre membri della classe a Godot:

  * **`ADD_PROPERTY(PropertyInfo, setter, getter)`**: Rende una variabile C++ visibile e modificabile nell'Inspector di Godot, collegandola a funzioni getter e setter.
  * **`ADD_SIGNAL(MethodInfo)`**: Dichiara un segnale personalizzato che la classe può emettere. Il segnale può poi essere connesso ad altri metodi nell'editor di Godot o via codice. Per lanciare il segnale si usa il metodo `emit_signal()`.

### Hot Reloading

L'hot reloading permette di ricaricare dinamicamente un'estensione dopo una ricompilazione senza dover riavviare l'editor di Godot, accelerando lo sviluppo. Per abilitarlo, imposta `reloadable = true` nella sezione `[configuration]` del file `.gdextension`.

### Documentazione della Classe

Godot può generare documentazione per le tue classi GDExtension. Eseguendo il comando `godot --doc-tool --gdextension-docs <path/to/docs/output>` dalla directory del progetto, verranno creati dei file XML. Questi file, una volta compilati nell'estensione, renderanno la documentazione visibile nell'help integrato dell'editor.

## 4 Glossario dei Termini Chiave

  * **`_bind_methods`**: Funzione statica protetta dove si registrano metodi, proprietà e segnali per esporli a Godot.
  * **`_notification`**: Funzione virtuale che riceve notifiche sugli eventi del ciclo di vita di un nodo (es. `NOTIFICATION_READY`).
  * **`ADD_PROPERTY` / `ADD_SIGNAL`**: Macro usate in `_bind_methods` per registrare proprietà e segnali.
  * **`Callable`**: Un oggetto che incapsula un metodo e l'istanza su cui chiamarlo, usato per connettere segnali.
  * **`ClassDB`**: Una classe singleton che gestisce la registrazione e l'accesso a tutte le informazioni sulle classi del motore e delle estensioni.
  * **`GDCLASS`**: Macro C++ essenziale per registrare una classe con il sistema di tipi di Godot.
  * **`GDREGISTER_CLASS`**: Macro per registrare una classe che sarà disponibile sia a runtime (nel gioco) che nell'editor (come uno script `@tool`).
  * **`GDREGISTER_RUNTIME_CLASS`**: Macro per registrare una classe che sarà disponibile solo a runtime, non nell'editor.
  * **`GDExtension`**: L'interfaccia C che permette di estendere Godot con codice nativo.
  * **`godot-cpp`**: Il binding C++ ufficiale per GDExtension.
  * **`Hot Reloading`**: La capacità di ricaricare un'estensione nell'editor senza riavviarlo.
  * **`memnew`**: Macro obbligatoria per allocare memoria per oggetti Godot, al posto di `new`.
  * **`SCons`**: Il sistema di build basato su Python usato da Godot.
  * **`Variant`**: Il tipo di dato fondamentale in Godot che può contenere qualsiasi altro tipo di dato (int, float, String, Object, etc.).


  * **Strumenti di Studio:** Ho utilizzato [NotebookLM](https://notebooklm.google.com/) per avere una visione d'insieme e prendere appunti da video e siti. È uno strumento utile, ma è importante estrarre e rielaborare le note personalmente.


