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

## Useful tools I used for studying
https://notebooklm.google.com/notebook/d552c69d-3d08-4594-a6f3-4d0eae14164b?original_referer=https%3A%2F%2Fwww.google.com%23&pli=1



this tool was used by me to have a better grasp with the gdextension creation is a way to get revision and notes about videos and sites so have an overview of the given sources.
Remember to get the notes out from the site though because it has a limited number of topic you can deepen up

# Generated notes for myself (this are in italian and are created by the tool that i mentioned)

Guida GDExtension C++ per Godot Guida allo Studio per GDExtension in C++
Questa guida allo studio è progettata per ripassare la tua comprensione di GDExtension in C++ per Godot Engine, basandosi sulle fonti fornite.

Domande a Risposta Breve
Rispondi a ciascuna delle seguenti domande in 2-3 frasi.

1. Qual è lo scopo principale di GDExtension e come differisce dal semplice modifica del codice sorgente di Godot?

2. Spiega la differenza tra "language bindings" e una GD extension che aggiunge un nuovo linguaggio di scripting.

3. Qual è l'obiettivo di design principale di GDScript e perché è significativo per i contributori al motore Godot?

4. Quali sono i requisiti di installazione fondamentali menzionati per seguire il workshop di Snopek su GDExtension in C++?

5. Qual è l'importanza del flag --recursive quando si clona il repository godot-cpp come sottomodulo Git?

6. Spiega il ruolo del file .gdextension in un progetto GDExtension.

7. Perché la funzione _bind_methods() è cruciale per le classi C++ registrate tramite GDScript, e cosa fa il macro GDCLASS?

8. Qual è la differenza pratica tra GDREGISTER_RUNTIME_CLASS e la registrazione di classi che funzionano sia in editor che in runtime?

9. Come si abilitano le funzionalità di "hot reloading" per un'estensione GD in Godot Editor?

10. Come si genera la documentazione per una classe GD extension personalizzata, e dove vengono memorizzati i file generati?

### Chiave di Risposta al Quiz

1. GDExtension è un'interfaccia C che permette di estendere le funzionalità di Godot (aggiungendo nuove classi native, plugin editor, linguaggi di scripting, ecc.) senza modificare il codice sorgente del motore. Ciò significa che le estensioni possono essere caricate dinamicamente e non richiedono una ricompilazione dell'intero motore Godot.

2. I "language bindings" adattano l'interfaccia C di GDExtension per facilitarne l'uso da un linguaggio di programmazione specifico (es. GDExtension-C++ per C++, Godot-Rust per Rust). Una GD extension che aggiunge un nuovo linguaggio di scripting, invece, permette di scrivere script in quel linguaggio e allegarli ai nodi, estendendo le opzioni di scripting disponibili in Godot.

3. L'obiettivo di design principale di GDScript è fornire la stessa API utilizzata all'interno di Godot stesso per i suoi moduli interni. Questo è significativo perché tutto ciò che un programmatore impara e scrive usando GDScript può essere direttamente trasferito alla contribuzione al motore Godot stesso, facilitando un passaggio più fluido da utente a contributore.

4. I requisiti fondamentali per il workshop includono un eseguibile di Godot 4.3 (o superiore), un compilatore C++ (GCC, Clang o MSVC), Python, e il sistema di build SCons. Per Windows, MSYS2 è raccomandato per un ambiente terminale simile a Linux.

5. Il flag --recursive è importante perché assicura che i sottomoduli Git, in particolare il repository godot-cpp che contiene i bindings C++ di GDExtension, vengano automaticamente clonati e inizializzati insieme al repository principale. Se dimenticato, i sottomoduli risulterebbero vuoti e richiederebbero un comando git submodule update --init separato per essere recuperati.

6. Il file .gdextension è un file di configurazione essenziale che informa Godot su come caricare un'estensione GD. Contiene sezioni per l'entry point (simbolo d'ingresso), la compatibilità minima di Godot, se l'estensione è ricaricabile, i percorsi delle librerie dinamiche per diverse piattaforme e architetture, e le dipendenze da altre librerie.

7. La funzione _bind_methods() è una funzione statica protetta che Godot chiama per scoprire quali metodi e proprietà di una classe C++ personalizzata dovrebbero essere esposti al motore Godot. Il macro GDCLASS si occupa di generare il codice di registrazione necessario e di collegare la classe al sistema di classi di Godot.

8. GDREGISTER_RUNTIME_CLASS registra una classe GDExtension in modo che funzioni solo durante l'esecuzione del gioco (runtime), non nell'editor. Per avere una classe che funziona sia nell'editor che nel gioco, come fanno le classi native del motore, è necessario utilizzare GDREGISTER_CLASS e le classi verranno trattate come "tool classes" per impostazione predefinita.

9. Per abilitare l'hot reloading, è necessario impostare la proprietà reloadable su true nella sezione [configuration] del file .gdextension. Dopo aver modificato questa impostazione, è necessario riavviare l'editor di Godot una volta affinché la modifica abbia effetto.

10. La documentazione per una classe GDExtension personalizzata viene generata eseguendo il comando godot --doc-tool --gdextension-docs <path/to/docs/output> dalla directory del progetto Godot. Questo comando crea file XML nella directory specificata (tipicamente doc_classes) che contengono i metadati della classe, e questi file vengono poi compilati nell'estensione GD durante la build.

### Glossario dei Termini Chiave

• GDExtension: Un'interfaccia C fornita da Godot Engine che consente agli sviluppatori di estendere le funzionalità del motore con codice nativo (come C++) senza modificare il codice sorgente di Godot e ricompilare l'intero motore. Le estensioni vengono caricate dinamicamente.

• godot-cpp: Il repository ufficiale che fornisce i bindings C++ per GDExtension. Consente agli sviluppatori C++ di interagire con l'API di Godot in un modo più idiomatico.

• SCons: Un sistema di build basato su Python utilizzato da Godot Engine e dalle estensioni GD per gestire il processo di compilazione.

• _bind_methods(): Una funzione statica protetta che deve essere implementata in ogni classe C++ di GDExtension che si desidera esporre a Godot. Registra metodi, proprietà e segnali della classe per renderli accessibili al motore.

• GDCLASS: Una macro C++ utilizzata nelle classi di GDExtension per impostare il codice di registrazione interno necessario affinché Godot riconosca la classe e la gestisca correttamente nel suo sistema di tipi.

• GDREGISTER_RUNTIME_CLASS: Una macro utilizzata in GDExtension per registrare una classe C++ che sarà disponibile solo a runtime (durante l'esecuzione del gioco), non nell'editor.

• GDREGISTER_CLASS: Una macro utilizzata in GDExtension per registrare una classe C++ che sarà disponibile sia a runtime che nell'editor (per impostazione predefinita, le classi native registrate in questo modo sono "tool classes").

• .gdextension file: Un file di configurazione in formato INI che specifica a Godot le librerie dinamiche da caricare per un'estensione GD, il suo entry point, la compatibilità di versione e le dipendenze.

• D_METHOD: Una macro utilizzata all'interno di _bind_methods() per creare un'informazione sul metodo che include il suo nome e i nomi degli argomenti, necessaria per registrare i metodi con Godot.

• ADD_PROPERTY: Una macro utilizzata in _bind_methods() per registrare una proprietà C++ in Godot, specificando il suo tipo, nome, suggerimenti (hint), e le funzioni getter e setter associate.

• ADD_SIGNAL: Una macro utilizzata in _bind_methods() per dichiarare un segnale personalizzato che la classe C++ può emettere, specificando il nome del segnale e i tipi e i nomi dei suoi argomenti.

• emit_signal(): Un metodo utilizzato per emettere un segnale precedentemente registrato, passando i valori degli argomenti definiti.

• Callable: Un oggetto che incapsula un metodo e l'istanza dell'oggetto su cui deve essere chiamato. Utilizzato per collegare segnali a metodi in GDExtension.

• PropertyInfo: Una struttura utilizzata per descrivere il tipo, il nome e i suggerimenti (hint) di una proprietà o di un argomento di un metodo/segnale quando si registrano con Godot.

• MethodInfo: Una struttura utilizzata per descrivere il nome e gli argomenti di un metodo o di un segnale quando si registrano con Godot.

• Hot Reloading: La capacità dell'editor di Godot di ricaricare dinamicamente un'estensione GD dopo una ricompilazione, senza richiedere il riavvio completo dell'editor. Questo è abilitato dall'opzione reloadable = true nel file .gdextension.

• _process(double delta): Un metodo virtuale di Godot che viene chiamato ogni frame di rendering. Utilizzato per la logica di gioco che dipende dal tempo di frame variabile.

• _physics_process(double delta): Un metodo virtuale di Godot che viene chiamato a intervalli fissi (tick fisico). Utilizzato per la logica di gioco basata sulla fisica e altre operazioni sensibili al tempo fisso.

• _notification(int what): Una funzione "magica" di Godot utilizzata per ricevere notifiche dal motore su vari eventi del nodo, come quando è "ready" (NOTIFICATION_READY). È spesso preferita a _ready() per le estensioni del motore per evitare override da script GDScript.

• memnew: Una macro o funzione speciale usata in Godot (e GDExtension) per allocare memoria per gli oggetti ereditanti da Object. Non si usa l'operatore new standard di C++ per gli oggetti Godot.

• Ref: Un template speciale usato in GDExtension per gestire il conteggio dei riferimenti per gli oggetti che ereditano da RefCounted, come le risorse. Il suo utilizzo è cruciale per prevenire memory leak.

• ClassDB: Una classe singleton in Godot che gestisce la registrazione e l'accesso alle informazioni sulle classi del motore e delle estensioni, inclusi metodi, proprietà e segnali.

• --doc-tool: Un argomento da riga di comando per l'eseguibile di Godot che consente di generare file XML per la documentazione delle classi.

• --gdextension-docs: Un argomento aggiuntivo per --doc-tool che specifica di generare la documentazione per le classi definite nelle estensioni GD.

• EXTENSION_API.JSON: Un file JSON che contiene i metadati completi dell'API di Godot, utilizzato dai bindings di GDExtension per generare le classi wrapper.

• GDVIRTUAL: Una macro utilizzata per registrare metodi virtuali di Godot (che possono essere sovrascritti da GDScript o da altre estensioni) nelle classi C++ di GDExtension.

• Singleton: In Godot, i singleton (o "Autoloads") sono nodi che vengono caricati automaticamente all'avvio del progetto e sono globalmente accessibili. Le estensioni GD possono registrare i propri singleton.

--------------------------------------------------------------------------------

Guida a GDExtension C++: Studio e Quiz

Guida allo Studio per GDExtension in C++

Questa guida allo studio è progettata per ripassare la tua comprensione di GDExtension in C++ per Godot, basandosi sui materiali forniti.

--------------------------------------------------------------------------------

Quiz a Risposta Breve

Rispondi a ciascuna domanda in 2-3 frasi.

1. Qual è lo scopo principale di GDExtension in Godot Engine?

2. Qual è la differenza fondamentale tra GDScript e una classe nativa (implementata tramite GDExtension) in termini di integrazione nel motore?

3. Spiega il ruolo di godot-cpp nel contesto dello sviluppo di GDExtension. È l'unica opzione ufficiale?

4. Quali sono i tre casi d'uso principali menzionati per GDExtension nella presentazione?

5. Perché è importante utilizzare memnew invece dell'operatore new standard di C++ quando si allocano oggetti Godot in un'estensione?

6. Descrivi la funzione del macro GDCLASS e del metodo _bind_methods quando si definisce una classe in GDExtension.

7. Qual è lo scopo del file .gdextension in un progetto GDExtension e quali sezioni chiave contiene?

8. Spiega perché, quando si estende il motore con GDExtension, il relatore raccomanda di usare la funzione _notification invece di _ready per l'inizializzazione.

9. Come si possono rendere visibili e modificabili le proprietà di una classe GDExtension nell'editor di Godot (Inspector)?

10. Descrivi il processo di hot-reloading per le estensioni GDExtension e quale impostazione è necessaria per abilitarlo.

--------------------------------------------------------------------------------

Chiave di Risposta al Quiz

1. **Qual è lo scopo principale di GDExtension in Godot Engine?** GDExtension è un'interfaccia C che consente agli sviluppatori di interagire con le funzionalità interne di Godot, come l'aggiunta di nuove classi native, plugin per l'editor o linguaggi di scripting. Permette di estendere il motore o di scrivere la logica di gioco in C++ per ottenere prestazioni native senza dover modificare il codice sorgente di Godot.

2. **Qual è la differenza fondamentale tra GDScript e una classe nativa (implementata tramite GDExtension) in termini di integrazione nel motore?** GDScript è un linguaggio di scripting integrato in Godot, e gli script vengono allegati ai nodi. Le classi native create con GDExtension, invece, sono tipi nativi che possono essere aggiunti direttamente all'albero delle scene e possono anche avere script GDScript allegati, combinando le funzionalità native con la logica di scripting.

3. Spiega il ruolo di godot-cpp nel contesto dello sviluppo di GDExtension. È l'unica opzione ufficiale? godot-cpp è il binding ufficiale di GDExtension per C++, fornendo la stessa API utilizzata internamente da Godot. Mentre godot-cpp è l'unico binding ufficiale, esistono molti altri binding sviluppati dalla community per diversi linguaggi di programmazione, adattando l'interfaccia C di GDExtension per facilitarne l'uso.

4. **Quali sono i tre casi d'uso principali menzionati per GDExtension nella presentazione?** I tre casi d'uso principali per GDExtension sono: integrare librerie C o C++ di terze parti in un gioco Godot, estendere Godot senza modificare il suo codice sorgente e scrivere la logica di gioco in C++ per ottenere prestazioni native in parti selezionate del gioco.

5. Perché è importante utilizzare memnew invece dell'operatore new standard di C++ quando si allocano oggetti Godot in un'estensione? memnew deve essere utilizzato perché Godot Engine impiega un allocatore di memoria speciale e richiede un'inizializzazione specifica per i suoi oggetti. L'uso dell'operatore new standard di C++ può causare crash o memory leak nell'ambiente Godot, poiché non rispetta le convenzioni di allocazione del motore.

6. **Descrivi la funzione del macro GDCLASS e del metodo _bind_methods quando si definisce una classe in GDExtension.** Il macro GDCLASS è essenziale per la registrazione delle classi GDExtension con Godot, gestendo il codice di registrazione boilerplate necessario. Il metodo _bind_methods (che deve essere protetto e statico) viene chiamato da Godot per scoprire quali metodi e proprietà della classe devono essere esposti all'editor e al sistema di scripting di Godot.

7. **Qual è lo scopo del file .gdextension in un progetto GDExtension e quali sezioni chiave contiene?** Il file .gdextension è il file di configurazione principale che Godot utilizza per caricare un'estensione. Contiene una sezione configuration che specifica il punto di ingresso dell'estensione (entry_symbol) e la versione minima di Godot compatibile (compatibility_minimum). La sezione libraries elenca i percorsi delle librerie dinamiche per ciascuna piattaforma e configurazione di build, e la sezione dependencies include eventuali librerie dinamiche aggiuntive.

8. **Spiega perché, quando si estende il motore con GDExtension, il relatore raccomanda di usare la funzione _notification invece di _ready per l'inizializzazione.** Il relatore raccomanda di usare _notification (in particolare NOTIFICATION_READY) perché il metodo _ready di una classe nativa può essere sovrascritto da uno script GDScript allegato. Usando _notification, si evita questo conflitto, imitando il modo in cui i nodi interni di Godot gestiscono l'inizializzazione e garantendo che il codice dell'estensione venga sempre eseguito.

9. **Come si possono rendere visibili e modificabili le proprietà di una classe GDExtension nell'editor di Godot (Inspector)?** Per rendere le proprietà visibili nell'Inspector, è necessario registrarle all'interno del metodo _bind_methods utilizzando la macro ADD_PROPERTY. Questa macro richiede un PropertyInfo che definisce il tipo, il nome e gli eventuali suggerimenti per la proprietà, oltre ai nomi dei metodi getter e setter associati alla proprietà.

10. **Descrivi il processo di hot-reloading per le estensioni GDExtension e quale impostazione è necessaria per abilitarlo.** L'hot-reloading consente di ricompilare un'estensione GDExtension e vederne le modifiche applicate nell'editor di Godot senza dover riavviare il motore. Per abilitarlo, è necessario impostare reloadable = true nella sezione configuration del file .gdextension. Funziona solo quando l'estensione è compilata in modalità debug.

--------------------------------------------------------------------------------

Glossario dei Termini Chiave

• GDExtension: Un'interfaccia C che permette di estendere Godot Engine con codice nativo in linguaggi come C++, Rust, Swift, Go, ecc., senza modificare il codice sorgente del motore.

• Godot Engine: Un motore di gioco multi-piattaforma, gratuito e open-source, utilizzato per sviluppare giochi 2D e 3D.

• godot-cpp: Il binding ufficiale di GDExtension per C++, che espone l'API interna di Godot agli sviluppatori di estensioni C++.

• Binding di Linguaggio: Un adattatore per l'interfaccia C di GDExtension che rende più facile l'uso di GDExtension da un particolare linguaggio di programmazione o ambiente.

• SCons: Un sistema di build basato su Python utilizzato per compilare Godot Engine e i progetti GDExtension.

• _bind_methods: Una funzione statica protetta all'interno di una classe GDExtension C++ che Godot chiama per registrare i metodi, le proprietà, i segnali e i metodi virtuali della classe, rendendoli accessibili dal motore.

• GDCLASS: Una macro C++ utilizzata nelle classi GDExtension per configurare il codice di registrazione interno necessario per l'integrazione con Godot.

• .gdextension file: Un file di configurazione JSON che informa Godot su come caricare un'estensione GDExtension, specificando il punto di ingresso, la compatibilità e i percorsi delle librerie per diverse piattaforme.

• memnew: Una macro (o funzione) speciale utilizzata in godot-cpp per allocare oggetti Godot, assicurando che venga utilizzato l'allocatore di memoria del motore e che vengano eseguite le inizializzazioni corrette.

• GDREGISTER_RUNTIME_CLASS: Una macro utilizzata in register_types.cpp per registrare una classe GDExtension con Godot, indicando che dovrebbe essere disponibile solo durante il runtime del gioco e non nell'editor.

• GDREGISTER_CLASS: Simile a GDREGISTER_RUNTIME_CLASS, ma registra la classe sia per l'uso in-game che nell'editor (per funzionalità come il tool scripting).

• _notification: Una funzione virtuale che può essere implementata nelle classi native di Godot e GDExtension per ricevere notifiche su vari eventi del ciclo di vita del nodo (es. NOTIFICATION_READY, NOTIFICATION_PROCESS).

• Hot-reloading: La capacità di ricaricare un'estensione GDExtension nell'editor di Godot senza dover riavviare il motore, permettendo un ciclo di sviluppo più rapido.

• ADD_PROPERTY: Una macro utilizzata in _bind_methods per registrare una proprietà C++ con il sistema di Godot, rendendola visibile e modificabile nell'Inspector. Richiede PropertyInfo e i nomi dei metodi getter/setter.

• ADD_SIGNAL: Una macro utilizzata in _bind_methods per dichiarare un segnale C++ che può essere emesso dalla classe e collegato ad altri metodi in Godot. Richiede MethodInfo per definire il nome del segnale e i suoi parametri.

• emit_signal: Un metodo utilizzato in una classe GDExtension per emettere un segnale precedentemente registrato, potenzialmente passando dei parametri.

• Callable: Un oggetto che incapsula un riferimento a un metodo e all'istanza dell'oggetto su cui deve essere chiamato, utilizzato per collegare segnali e chiamare metodi.

• Metodo Virtuale (Godot): Un metodo registrato tramite GDExtension che può essere sovrascritto da script GDScript o da altre estensioni, consentendo una logica personalizzata pur mantenendo l'interfaccia definita in C++.

• GD_VIRTUAL_CALL: Una macro utilizzata per chiamare un metodo virtuale (specifico di Godot) definito in C++, che può essere stato sovrascritto da uno script.

• Sistema di Documentazione GDExtension: Il processo di generazione di file XML con godot --doc-tool e la loro compilazione nell'estensione per visualizzare la documentazione della classe nell'editor di Godot.

--------------------------------------------------------------------------------

Estensione Godot con C++: Guida Completa GDExtension

Le fonti forniscono una panoramica dettagliata su come estendere le funzionalità del motore di gioco Godot utilizzando GDExtension con C++. Il testo di YouTube illustra il processo pratico di creazione, compilazione e implementazione di classi C++ personalizzate, la gestione di proprietà e segnali, e l'integrazione con GDScript. La documentazione di Godot, invece, offre un riferimento strutturato che spiega i fondamenti di GDExtension, inclusa la configurazione del progetto, la creazione delle associazioni C++, e la struttura dei file necessari per lo sviluppo di plugin, con un focus sull'esempio pratico. Insieme, le risorse mostrano sia il "come fare" attraverso dimostrazioni, sia il "cosa fare" tramite la documentazione di riferimento.

--------------------------------------------------------------------------------

Estensione Godot con C++: Guida Completa GDExtension

Le fonti forniscono una panoramica dettagliata su come estendere le funzionalità del motore di gioco Godot utilizzando GDExtension con C++. Il testo di YouTube illustra il processo pratico di creazione, compilazione e implementazione di classi C++ personalizzate, la gestione di proprietà e segnali, e l'integrazione con GDScript. La documentazione di Godot, invece, offre un riferimento strutturato che spiega i fondamenti di GDExtension, inclusa la configurazione del progetto, la creazione delle associazioni C++, e la struttura dei file necessari per lo sviluppo di plugin, con un focus sull'esempio pratico. Insieme, le risorse mostrano sia il "come fare" attraverso dimostrazioni, sia il "cosa fare" tramite la documentazione di riferimento.

--------------------------------------------------------------------------------

Estensione Godot con C++: Guida Completa GDExtension

Le fonti forniscono una panoramica dettagliata su come estendere le funzionalità del motore di gioco Godot utilizzando GDExtension con C++. Il testo di YouTube illustra il processo pratico di creazione, compilazione e implementazione di classi C++ personalizzate, la gestione di proprietà e segnali, e l'integrazione con GDScript. La documentazione di Godot, invece, offre un riferimento strutturato che spiega i fondamenti di GDExtension, inclusa la configurazione del progetto, la creazione delle associazioni C++, e la struttura dei file necessari per lo sviluppo di plugin, con un focus sull'esempio pratico. Insieme, le risorse mostrano sia il "come fare" attraverso dimostrazioni, sia il "cosa fare" tramite la documentazione di riferimento.

--------------------------------------------------------------------------------

Estensione Godot con C++: Guida Completa GDExtension

Le fonti forniscono una panoramica dettagliata su come estendere le funzionalità del motore di gioco Godot utilizzando GDExtension con C++. Il testo di YouTube illustra il processo pratico di creazione, compilazione e implementazione di classi C++ personalizzate, la gestione di proprietà e segnali, e l'integrazione con GDScript. La documentazione di Godot, invece, offre un riferimento strutturato che spiega i fondamenti di GDExtension, inclusa la configurazione del progetto, la creazione delle associazioni C++, e la struttura dei file necessari per lo sviluppo di plugin, con un focus sull'esempio pratico. Insieme, le risorse mostrano sia il "come fare" attraverso dimostrazioni, sia il "cosa fare" tramite la documentazione di riferimento.

--------------------------------------------------------------------------------

Guida Sviluppo GDExtension C++ per Godot

Guida allo Studio di GDExtension in C++ per Godot

Panoramica

Questa guida allo studio copre i concetti fondamentali e le procedure per lo sviluppo di estensioni Godot (GDExtension) utilizzando C++. Si basa sulla presentazione "C++ for Godot with GDExtension – David Snopek – GodotCon 2024" e la documentazione ufficiale di Godot Engine. La GDExtension fornisce un'interfaccia C che permette l'interazione profonda con gli interni di Godot, abilitando l'aggiunta di nuove classi native, plugin per l'editor, e linguaggi di scripting, estendendo il motore senza modificare il suo codice sorgente.

--------------------------------------------------------------------------------

Sezione 1: Fondamenti di GDExtension

Domande a Risposta Breve

1. **Cos'è GDExtension?** GDExtension è un'interfaccia C che consente agli sviluppatori di estendere il motore Godot con codice nativo senza dover modificare il codice sorgente del motore stesso. Permette l'aggiunta di nuove classi native (nodi, risorse, oggetti), plugin per l'editor e nuovi linguaggi di scripting.

2. **Qual è lo scopo principale di GDScript e GDExtension in Godot?** GDScript è il linguaggio di scripting nativo di Godot, progettato per essere facile da imparare e da usare per la logica di gioco. GDExtension, invece, serve a estendere le funzionalità del motore con codice C++ o altri linguaggi, offrendo prestazioni native e la possibilità di integrare librerie di terze parti.

3. **Qual è la differenza tra un "binding di linguaggio" di GDExtension e una GDExtension che aggiunge un nuovo linguaggio di scripting?** Un binding di linguaggio adatta l'interfaccia C di GDExtension per facilitarne l'uso da un linguaggio di programmazione specifico (es. GDNative-CPP per C++). Una GDExtension che aggiunge un nuovo linguaggio di scripting, invece, abilita la scrittura di script per i nodi di Godot in quel nuovo linguaggio (es. Luau).

4. **Cosa significa che godot-cpp mira a fornire la stessa API utilizzata all'interno di Godot stesso?** Significa che l'API esposta da godot-cpp per lo sviluppo di GDExtension è quasi identica a quella usata internamente dai moduli del motore Godot. Questo permette agli sviluppatori di riutilizzare le conoscenze acquisite per contribuire direttamente al codice sorgente del motore.

5. **Quali sono alcuni casi d'uso principali per GDExtension, come menzionato da David Snopek?** I casi d'uso principali includono l'integrazione di librerie C o C++ di terze parti, l'estensione di Godot senza modificare il suo codice sorgente, la scrittura della logica di gioco in C++ e l'ottenimento di prestazioni native per parti selezionate del gioco.


--------------------------------------------------------------------------------

Sezione 2: Procedura di Sviluppo di GDExtension

Domande a Risposta Breve

1.

**Qual è il primo passo per impostare un nuovo progetto GDExtension in C++ utilizzando il template ufficiale?**Il primo passo è andare al progetto template godot-cpp su GitHub, utilizzare il pulsante "Use this template" per creare un nuovo repository, e quindi clonare quel repository localmente utilizzando git clone --recursive per includere il sottomodulo godot-cpp.

2.

**Perché è importante usare --recursive quando si clona il repository del template godot-cpp?**È importante perché il repository del template godot-cpp include godot-cpp come sottomodulo Git. L'opzione --recursive assicura che anche il sottomodulo venga inizializzato e scaricato, fornendo tutte le dipendenze necessarie per la compilazione.

3.

**Qual è lo scopo del file SConstruct e cosa bisogna modificare al suo interno in un nuovo progetto GDExtension?**Il file SConstruct è il file di configurazione per il sistema di build SCons. In un nuovo progetto GDExtension, è necessario modificare extension_name per dare un nome specifico all'estensione e, se applicabile, project_path se la cartella del progetto demo di Godot è stata rinominata.

4.

**Come si assicura che Godot trovi la libreria dinamica della tua GDExtension su diverse piattaforme?**Si assicura che Godot trovi la libreria dinamica della GDExtension configurando la sezione [libraries] nel file .gdextension. Questa sezione specifica i percorsi ai file della libreria (.dll, .so, .dylib, .xcframework) per ciascuna piattaforma e configurazione (debug/release).

5.

**Quali sono i passaggi per aggiornare la documentazione interna della tua GDExtension in Godot?**Per aggiornare la documentazione, si usa il comando godot --doc-tool --gdextension-docs <output_directory> dalla directory del progetto Godot per generare i file XML. Una volta modificati (aggiungendo descrizioni, ecc.), basta ricompilare il progetto GDExtension con SCons, e la documentazione sarà integrata.

--------------------------------------------------------------------------------

Sezione 3: Esempi Pratici e Concetti Avanzati

Domande a Risposta Breve

1.

Spiega l'uso di memnew in GDExtension C++ invece dell'operatore new standard. memnew è un macro speciale che deve essere utilizzato per istanziare oggetti Godot in C++ (anche all'interno del motore stesso). Questo perché Godot utilizza un allocatore di memoria personalizzato e richiede un'inizializzazione speciale, che l'operatore new standard non fornisce. L'uso di new potrebbe causare crash.

2.

**Perché _notification può essere preferibile a _ready quando si estende il motore con una GDExtension?**La funzione _notification (in particolare per NOTIFICATION_READY) è spesso preferita a _ready nelle GDExtension che estendono il motore perché _ready da uno script GDScript può sovrascrivere _ready dalla classe nativa. Usare _notification evita questo conflitto e mima il comportamento interno del motore.

3.

**Come si registrano i valori di un enum C++ con Godot in una GDExtension?**Per registrare i valori di un enum C++ con Godot, si usa ClassDB::bind_enum_constant all'interno della funzione _bind_methods. È anche necessario utilizzare VARIANT_ENUM_CAST per consentire il casting da e verso Variant.

4.

**Descrivi come implementare e chiamare un metodo virtuale GD in una GDExtension C++.**Per implementare un metodo virtuale GD, si dichiara una funzione con il prefisso _ (es. _get_next_light) e si utilizza il macro GDVIRTUAL per la registrazione in _bind_methods, specificando il numero di argomenti, se ha un valore di ritorno (R), e se è const (C). La chiamata avviene tramite GDVIRTUAL_CALL.

5.

**Qual è l'obiettivo delle "runtime classes" in GDExtension e come si registrano?**Le "runtime classes" sono classi GDExtension che vengono eseguite solo quando il gioco è in modalità di gioco, non nell'editor. Questo è utile per la logica di gioco che non dovrebbe influenzare il comportamento dell'editor. Si registrano usando il macro GDREGISTER_RUNTIME_CLASS invece di GDREGISTER_CLASS.

--------------------------------------------------------------------------------

Domande in Formato Saggio

1.

Discuti le principali ragioni per cui uno sviluppatore potrebbe scegliere di usare GDExtension con C++ anziché GDScript per la logica di gioco in Godot. Considera vantaggi in termini di prestazioni, integrazione di librerie e complessità del progetto.

2.

Analizza il processo di build di un progetto GDExtension in C++ dal download del template alla generazione della libreria dinamica. Spiega il ruolo di SCons, godot-cpp, e le modifiche necessarie ai file di configurazione.

3.

Confronta e contrasta la gestione delle proprietà e dei segnali nelle GDExtension C++ con il modo in cui sono gestiti in GDScript. Sottolinea le differenze nella sintassi e nelle implicazioni sul flusso di lavoro.

4.

Spiega come le GDExtension C++ possono essere utilizzate per "estendere il motore" (ad esempio, con il caso d'uso del semaforo) e come questo differisce dallo scripting della logica di gioco. Discuti le considerazioni di design, come l'uso di _notification vs _ready, e l'integrazione con l'editor.

5.

Immagina di dover creare una GDExtension complessa che interagisce con un'API di terze parti (ad esempio, una libreria di fisica). Descrivi i passaggi chiave dalla progettazione alla distribuzione, includendo considerazioni su dipendenze, cross-compilazione e documentazione.

--------------------------------------------------------------------------------

Glossario dei Termini Chiave

• API (Application Programming Interface): Un insieme di definizioni di subroutine, protocolli e strumenti per la creazione di software applicativo. In Godot, si riferisce all'interfaccia che gli sviluppatori utilizzano per interagire con il motore.

• Binding di Linguaggio (Language Binding): Un wrapper o un adattatore che consente a un linguaggio di programmazione di utilizzare librerie o API scritte in un altro linguaggio. Per GDExtension, i binding (come godot-cpp) adattano l'interfaccia C per facilitarne l'uso da C++.

• _bind_methods: Una funzione statica protetta in una classe GDExtension C++ dove vengono registrati tutti i metodi, proprietà, segnali ed enumerazioni che devono essere esposti all'API di Godot e all'editor.

• Callable: Un oggetto in Godot che incapsula le informazioni necessarie per chiamare un metodo su un'istanza di un oggetto specifico. Utilizzato per connettere segnali e fare chiamate a metodi dinamici.

• ClassDB: Una classe Singleton in Godot (e godot-cpp) che gestisce la registrazione e la reflection di tutte le classi disponibili nel motore, inclusi i nodi, le risorse e le classi GDExtension.

• Cross-compilazione: Il processo di compilazione di codice sorgente per un'architettura o un sistema operativo diverso da quello su cui sta avvenendo la compilazione. Necessario per distribuire GDExtension su diverse piattaforme.

• DLL (Dynamic-Link Library) / SO (Shared Object) / DyLib (Dynamic Library): Nomi specifici della piattaforma per le librerie dinamiche, che contengono codice che può essere caricato ed eseguito in fase di runtime da un'applicazione. Le GDExtension sono compilate in questi formati.

• emit_signal: Una funzione utilizzata nelle classi Godot (e GDExtension) per notificare gli oggetti connessi che un determinato evento si è verificato.

• entry_symbol: Una stringa definita nel file .gdextension che specifica il nome della funzione di inizializzazione principale che Godot chiamerà al caricamento della libreria GDExtension.

• GDCLASS: Un macro C++ essenziale utilizzato nelle classi GDExtension per gestire automaticamente il boilerplate di registrazione e reflection necessario affinché Godot riconosca la classe.

• GDExtension: Una tecnologia in Godot 4+ che permette di estendere il motore con codice nativo (come C++) tramite un'interfaccia C, senza richiedere la ricompilazione del motore stesso.

• gdexample.gdextension: Il file di configurazione principale per una GDExtension, in formato INI, che descrive come Godot deve caricare e gestire la libreria dell'estensione, specificando compatibilità, percorsi delle librerie e altre proprietà.

• godot-cpp: Il repository ufficiale del binding C++ per GDExtension. Fornisce wrapper C++ attorno all'interfaccia C di GDExtension, rendendola più ergonomica per gli sviluppatori C++.

• Godot Engine: Un motore di gioco multi-piattaforma open source, rilasciato sotto licenza MIT.

• GDScript: Il linguaggio di scripting leggero e dinamico di Godot, ottimizzato per lo sviluppo di giochi e l'integrazione con il motore.

• GDREGISTER_CLASS: Macro usato per registrare una classe C++ GDExtension che sarà disponibile sia in runtime (nel gioco) che nell'editor di Godot. Simile a uno script @tool.

• GDREGISTER_RUNTIME_CLASS: Macro usato per registrare una classe C++ GDExtension che sarà disponibile solo in runtime (nel gioco), non nell'editor di Godot.

• GDVIRTUAL / GDVIRTUAL_CALL: Macro utilizzati per dichiarare e chiamare metodi "virtuali GD" (o "virtual method calls") in una GDExtension C++. Questi metodi possono essere sovrascritti da script GDScript o altre estensioni, fornendo un meccanismo di polimorfismo tra C++ e scripting.

• Hot Reloading: La capacità di ricompilare e ricaricare il codice di un'estensione o di uno script in un ambiente di sviluppo (come l'editor di Godot) senza dover riavviare l'applicazione o il progetto.

• memnew: Un macro utilizzato in godot-cpp (e internamente in Godot) per allocare memoria per gli oggetti Godot. È fondamentale usarlo al posto di new a causa del sistema di gestione della memoria personalizzato di Godot.

• ModuleInitializationLevel: Un'enumerazione che indica la fase di inizializzazione in cui un modulo GDExtension viene caricato (es. MODULE_INITIALIZATION_LEVEL_SCENE, MODULE_INITIALIZATION_LEVEL_EDITOR).

• _notification: Una funzione virtuale in Object (e quindi Node e altre classi Godot) che riceve vari tipi di notifiche dal motore, come NOTIFICATION_READY (equivalente a _ready). Spesso preferita a _ready nelle GDExtension per evitare override da script.

• PropertyInfo: Una struttura dati utilizzata in ClassDB::bind_method e ADD_PROPERTY per descrivere una proprietà (il suo tipo, nome, suggerimenti, ecc.) che verrà esposta all'editor di Godot.

• SCons: Un sistema di build open source basato su Python, utilizzato da Godot per la compilazione del motore e delle GDExtension.

• Singleton: In Godot, una classe o un nodo che esiste come una singola istanza globale accessibile da qualsiasi parte del progetto (spesso chiamati "Autoloads").

• Submoduli Git: Una funzionalità di Git che consente di includere un altro repository Git come sottocartella all'interno del proprio repository, mantenendo la sua cronologia Git separata. Utile per gestire dipendenze come godot-cpp.

• TextureRect: Un nodo di controllo UI in Godot utilizzato per disegnare una texture all'interno di un rettangolo.

• Variant: Il tipo di dati fondamentale in Godot, un tipo "any" che può contenere qualsiasi tipo di dato integrato (int, float, String, Vector2, Object, ecc.). Tutti i dati passati tra C++ e Godot API sono spesso avvolti in Variant.

