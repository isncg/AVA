﻿void imgui_pangram() {
    // pangrams & utf8 samplers
    // [src] http://clagnut.com/blog/2380/
    // [src] https://elinux.org/UTF8_Sampler
    // [src] http://generator.lorem-ipsum.info/
    static bool show_glyph_window = 1;
    if( show_glyph_window ) {
        ImGui::SetNextWindowSize(ImVec2(500,600), ImGuiSetCond_FirstUseEver);
        if( ImGui::Begin("Font pangram glyph tests", &show_glyph_window) ) {
            const char *tabs[] = {
             "Emojis/MD",      ICON_MD_FACE,
             "Arabic",         "صِف خَلقَ خَودِ كَمِثلِ الشَمسِ إِذ بَزَغَت — يَحظى الضَجيعُ بِها نَجلاءَ مِعطارِ",
             "Armenian",       "Կրնամ ապակի ուտել և ինծի անհանգիստ չըներ",
             "Belarusian",     "У Іўі худы жвавы чорт у зялёнай камізэльцы пабег пад'есці фаршу з юшкай",
             "Braille (EN)",   "⠊⠀⠉⠁⠝⠀⠑⠁⠞⠀⠛⠇⠁⠎⠎⠀⠁⠝⠙⠀⠊⠞⠀⠙⠕⠑⠎⠝⠞⠀⠓⠥⠗⠞⠀⠍⠑...",
             "Bulgarian",      "Ах чудна българска земьо, полюшвай цъфтящи жита.",
             "Chinese",        "我能吞下玻璃而不伤身体。...",
             "Chinese(TD)",    "我能吞下玻璃而不傷身體。...",
             "Czech",          "Nechť již hříšné saxofony ďáblů rozezvučí síň úděsnými tóny waltzu, tanga a quickstepu.",
             "Dutch",          "Pa's wijze lynx bezag vroom het fikse aquaduct.",
             "English",        "The quick brown fox jumps over the lazy dog.",
             "Estonian",       "Põdur Zagrebi tšellomängija-följetonist Ciqo külmetas kehvas garaažis",
             "Ethiopian",      "ሰማይ አይታረስ ንጉሥ አይከሰስ። ብላ ካለኝ እንደአባቴ በቆመጠኝ። ጌጥ ያለቤቱ ቁምጥና ነው። ...",
             "Finnish",        "Charles Darwin jammaili Åken hevixylofonilla Qatarin yöpub Zeligissä.",
             "French",         "Voix ambiguë d’un cœur qui au zéphyr préfère les jattes de kiwi.",
             "Georgian",       "მინას ვჭამ და არა მტკივა...",
             "German",         "Victor jagt zwölf Boxkämpfer quer über den großen Sylter Deich.",
             "Greek(Ancient)", "Ἄδμηθ’, ὁρᾷς γὰρ τἀμὰ πράγμαθ’ ὡς ἔχει, λέξαι θέλω σοι πρὶν θανεῖν ἃ βούλομαι.",
             "Greek",          "Ταχίστη αλώπηξ βαφής ψημένη γη, δρασκελίζει υπέρ νωθρού κυνός.",
             "Guarani",        "Hĩlandiagua kuñanguéra oho peteĩ saʼyju ypaʼũme Gavõme omboʼe hag̃ua ingyleñeʼẽ mitãnguérare neʼẽndyʼỹ.",
             "Hebrew",         "דג סקרן שט בים מאוכזב ולפתע מצא לו חברה",
             "Hindi",          "ऋषियों को सताने वाले दुष्ट राक्षसों के राजा रावण का सर्वनाश करने वाले विष्णुवतार भगवान श्रीराम, अयोध्या के महाराज दशरथ के बड़े सपुत्र थे।",
             "Hungarian",      "Jó foxim és don Quijote húszwattos lámpánál ülve egy pár bűvös cipőt készít.",
             "Icelandic",      "Kæmi ný öxi hér, ykist þjófum nú bæði víl og ádrepa.",
             "Igbo",           "Nne, nna, wepụ he’l’ụjọ dum n’ime ọzụzụ ụmụ, vufesi obi nye Chukwu, ṅụrịanụ, gbakọọnụ kpaa, kwee ya ka o guzoshie ike; ọ ghaghị ito, nwapụta ezi agwa",
             "IPA",            "[ɢʷɯʔ.nas.doːŋ.kʰlja] [ŋan.ȵʑi̯wo.ɕi̯uĕn.ɣwa]",
             "Irish",          "Ċuaiġ bé ṁórṡáċ le dlúṫspád fíorḟinn trí hata mo ḋea-ṗorcáin ḃig.",
             "Japanese",       "いろはにほへと ちりぬるを わかよたれそ つねならむ うゐのおくやま けふこえて あさきゆめみし ゑひもせす（ん）",
             "Japanese/2",     "私はガラスを食べられます。それは私を傷つけません。",
             "Korean",         "키스의 고유조건은 입술끼리 만나야 하고 특별한 기술은 필요치 않다",
             "Latvian",        "Muļķa hipiji mēģina brīvi nogaršot celofāna žņaudzējčūsku.",
             "Lithuanian",     "Įlinkdama fechtuotojo špaga sublykčiojusi pragręžė apvalų arbūzą.",
             "Macedonian",     "Ѕидарски пејзаж: шугав билмез со чудење џвака ќофте и кељ на туѓ цех.",
             "Maths",          "2H₂+O₂⇌2H₂O,R=4kΩ,⌀200mm;⎷a²+b³c₈;∀x∈ℝ:⌈x⌉=−⌊−x⌋,α∧¬β=¬(¬α∨β);ℕ⊆ℕ₀⊂ℤ⊂ℚ⊂ℝ⊂ℂ",
             "Mongolian",      "Щётканы фермд пийшин цувъя. Бөгж зогсч хэльюү",
             "Nepali",         "﻿म काँच खान सक्छू र मलाई केहि नी हुन्‍न् ।",
             "Norwegian",      "Høvdingens kjære squaw får litt pizza i Mexico by",
             "Old Norse(rune)","ᛖᚴ ᚷᛖᛏ ᛖᛏᛁ ᚧ ᚷᛚᛖᚱ ᛘᚾ ᚦᛖᛋᛋ ᚨᚧ ᚡᛖ ᚱᚧᚨ ᛋᚨᚱ ...",
             "Polish",         "Pchnąć w tę łódź jeża lub ośm skrzyń fig.",
             "Portuguese",     "Luís argüia à Júlia que «brações, fé, chá, óxido, pôr, zângão» eram palavras do português.",
             "Quotes",         "‘single’ “double” “curly” ‚deutsche‘ „Anführ“ \"'´`",
             "Romanian",       "Înjurând pițigăiat, zoofobul comandă vexat whisky și tequila.",
             "Russian",        "Эх, чужак! Общий съём цен шляп (юфть)—вдрызг!.",
             "Sanskrit",       "खगौघाङचिच्छौजा झाञ्ज्ञोऽटौठीडडण्ढणः। तथोदधीन् पफर्बाभीर्मयोऽरिल्वाशिषां",
             "Serbian",        "Ајшо, лепото и чежњо, за љубав срца мога дођи у Хаџиће на кафу / Ajšo, lepoto i čežnjo, za ljubav srca moga dođi u Hadžiće na kafu.",
             "Slovak",         "Kŕdeľ ďatľov učí koňa žrať kôru + š",
             "Spanish",        "Benjamín pidió una bebida de kiwi y fresa; Noé, sin vergüenza, la más exquisita champaña del menú. + ḷḷ ḥ",
             "Swedish",        "Yxskaftbud, ge vår wczonmö iqhjälp.",
             "Taiwanese",      "Góa ē-tàng chia̍h po-lê, mā bē tio̍h-siong.",
             "Thai",           "เป็นมนุษย์สุดประเสริฐเลิศคุณค่า กว่าบรรดาฝูงสัตว์เดรัจฉาน จงฝ่าฟันพัฒนาวิชาการ อย่าล้างผลาญฤๅเข่นฆ่าบีฑาใคร ไม่ถือโทษโกรธแช่งซัดฮึดฮัดด่า หัดอภัยเหมือนกีฬาอัชฌาสัย ปฏิบัติประพฤติกฎกำหนดใจ พูดจาให้จ๊ะๆ จ๋าๆ น่าฟังเอยฯ",
             "Tibetan",        "༈ དཀར་མཛེས་ཨ་ཡིག་ལས་འཁྲུངས་ཡེ་ཤེས་གཏེར། །ཕས་རྒོལ་ཝ་སྐྱེས་ཟིལ་གནོན་གདོང་ལྔ་བཞིན། །ཆགས་ཐོགས་ཀུན་བྲལ་མཚུངས་མེད་འཇམ་བྱངས་མཐུས། །མ་ཧཱ་མཁས་པའི་གཙོ་བོ་ཉིད་གྱུར་ཅིག།",
             "Turkish",        "Saf ve haydut kız çocuğu bin plaj görmüş.",
             "Ukrainian",      "Жебракують філософи при ґанку церкви в Гадячі, ще й шатро їхнє п’яне знаємо.",
             "Vietnamese",     "Do bạch kim rất quý nên sẽ dùng để lắp vô xương",
             "Welsh",          "Parciais fy jac codi baw hud llawn dŵr ger tŷ Mabon.",
             "Yiddish",        "איך קען עסן גלאָז און עס טוט מיר נישט װײ",

             0, 0 };
             ImGui::Columns(2);
             for( int i = 0; tabs[i]; ) {
                ImGui::Text(tabs[i++]);
                ImGui::NextColumn();
                ImGui::Text(tabs[i++]);
                ImGui::NextColumn();
             }
             ImGui::Columns(1);
        }
        ImGui::End();
    }
}
