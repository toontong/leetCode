#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;


bool comp(const string& s1,const string& s2 )  {
    return s1.length()> s2.length();
}


class Solution {
    public:
       int maxProduct(vector<string>& words){
            if(words.size()<=1)return 0;

            int *mark = new int[words.size()];

            for (int i=0; i<words.size();i++){
                    string s = words[i];
                    mark[i] = 0;
                    for(int j=0;j<s.length();j++)
                            mark[i] |=  (1 << (s[j] - 'a'));
            }
            int ans = 0;
            for (int i=0; i < words.size()-1;i++){
                    for (int j=i+1; j<words.size();j++){
                            if((mark[i] & mark[j]) ==0){
                                    cout<<words[i]<<"  | "<< words[j]<<endl;
                                    int n = words[i].length()*words[j].length() ;
                                    if (n>=ans)ans=n;
                            }
                    }
            }
            delete []mark;
            return ans;
        }
};

int test(string str2[], int result, int size){
        vector<string> t3(str2, str2+size);
        int s= Solution().maxProduct(t3);
        if(result != s){
            cout <<"res-->"<<result<< " solution->"<< s << endl;
        }else{
            cout<<"ok"<<endl;
        }

}

int main(){
 string str5[]={"ccd","accaceddeeeaefc","bcaffa","bbcfafbb","accacfebbabbeedfbfdb","beddecbffcdaededdaefdedfdea","cf","ddafdcbd","bbafacebacaefdaffccebddff","ebccffcddbeddccacceccaec","becfbfdccdfdeadfbfaddbcded","cbabeaaeabefedbaeaedc","dfadbbdbead","cafaefdcd","eccdbfceafeeeacfcddc","dbabbcdbb","abfbfbffcbebde","cfaadaa","fc","faebcabb","adbacebabcaaccbdeaffff","aeaefccf","dbacbeeabdbcdfccabebaecfef","ecdadeefcaddffaececffa","defcabf","abbcecbccbdaebaecaefabed","dfeeebcbaaefc","aecccbcbbdddb","dcfabacec","fccfbacbacddeaaea","dfdbfacbacbecb","cbfeebdbfecb","cffaacacbde","aafd","bdcebbbebd","afeffadcfcdacfba","dafeefbcdfaffcfacee","dcbbebfbedafedcdbab","cafaf","bcbcccfdebdd","efaaaacccff","cffbead","ebcfccfcddffdec","fffdfdcec","beeafefbdfa","cdfdbccfbaaeffcabab","ddadcbabbcb","decfaeabbecebaebeaddedae","cdcbfffbebae","aeccefcbcbbddfdc","ffefedaf","cddbabccafaffeafeedcbedbdad","eddeeccfedcefadfdfebfacb","aca","ffdcafaddcddf","ef","bbbbffe","ffccfebabaadcffacbbb","cbdeddfddffacbeeeebafebabda","ddeecb","cffdc","edcffcebadf","becbcadcafddcfbbeeddbfffcab","abcbaceeaeaddd","cfeffceebfaeefadaaccfa","eaccddb","caeafbfafecd","becaafdbaadbfecfdfde","ecabaaeafbfbcbadaac","bdcdffcfaeebeedfdfddfaf","dbbfbaeecbfcdebad","cceecddeeecdbde","beec","adbcfdbfdbccdcffffbcffbec","bbbbfe","cdaedaeaad","dadbfeafadd","fcacaaebcedfbfbcddfc","ceecfedceac","dada","ccfdaeffbcfcc","eadddbbbdfa","beb","fcaaedadabbbeacabefdabe","dfcddeeffbeec","defbdbeffebfceaedffbfee","cffadadfbaebfdbadebc","fbbadfccbeffbdeabecc","bdabbffeefeccb","bdeeddc","afcbacdeefbcecff","cfeaebbbadacbced","edfddfedbcfecfedb","faed","cbcdccfcbdebabc","efb","dbddadfcddbd","fbaefdfebeeacbdfbdcdddcbefc","cbbfaccdbffde","adbcabaffebdffad"};
test(str4,39, sizeof(str5)/sizeof(str5[0]));

        string str4[] = {"bcedengp","jegidiicfohjimcccnkagmanbkkmbmlfabgammipaiepjnfi","condccpkmicalappldjbnlepdplggcmcnilkkinefgdmldegcjbimfaikfjldpoplcakdkglpnlnjkojhcglig","gnpddclieoneddfhojknjkkaehlkgegpfbnopjcnogcicokhlffd","edjnfgmoaningkmcfncodeganbmbhamoighbojdcjcdicipdobbcahil","hkjkfjkmaagcgpcimmljfghmkgekmkh","homffkkkipepcbmipn","ipkakmolkhecdddpdpcphafiaofgb","jeejnmdgokbmkmpdlkgiolkemenahkoidimoeidpagefpcokodcmjdjcbkaeaogmcbenhdcnegg","eapffhadafnnalkkobdbmpnnhfeg","opfknkinpknipgjhcjdgffjoippjcnfabdejn","fhnpojhnfiogkdgffgjc","nlhmgmigpbconl","jjlejejegngdljbgkkomfacjfjoemilaeofgdhiip","imagjifpapmgej","mjkdjbjmbhfbkbjnahlenhkdnnpplpenidahdkokeihmjjfojndiidlbkh","ihpnbcncpigllmpdekkjbdemobbdjemafeioiaoibgabakmmkklopoeppibdfhdlallcedldclmkhpmkkdg","plfpneanjljoebogkbfabdnkanodgljecaemcffnoicmdbgkkfma","afianbgmdff","bhobekifemheldcamckoccfdcnmdcmnfbodfldbhgoikplggehfokkolacadgoholcdbgcpgoanmmnmika","bnjklpaiklipbcbphhfjoibhhhljoppcfjdno","ickghheki","kacnagbficmhikbdeldcagg","laamledghhflcjjdfofdojkfbkl","aacafidfbpmimlclhcjignenchbdjcgfbdiegmohfloieajekfgcmamifbmkjnoaipcfmbejmkigaekcgemffemfcnkhhkkj","hlcdacefjodhllpbhkkokepmcdmmigclefoglahalejfiipjelmhkbhjblmbkgpimjbmplmgclfiifncckibpkjlnkbgcph","ohdadlaokhbhlgiepimmdmfegefpbkbcodnfebbcfakfijhnefg","lgeokomognpmfblbhekgnlpdohnpkoajionmjhhagenafmcdpgfiidlmnogigfipdpgjljlgakaoammekhmjhecnmghecdhljl","kmjkfdbibcnkinkagennlcfbajffdkgajloinjakombekjcbh","iofimmgddmjidfmmloofkdihlffaakapkhchmcclocdbandon","kpbmkbdfgobjebadjdhgkglakcbjpjkkpd","ghjahnmogdofblllfpdfbhohkmdingfmaofoflchbhpkjccffadnbd","lobkhmbgcjdpkemkijhddofpadcgabbfadkhmdmgippceaapeabhbemoejfhejhjncceckddmldpbdlmeljmcpbnaflolihhaojlp","nlcmhaaebniidhgammlkhpphglanihnmpchebbehfgjeegdkicbnnkgnaipdhiemigfgaoehedph","ecdnklamhjbkemhngkldlbbbkalepnlci","eokamphdgfobplgmnhcigcjalmbldgmfcgbppcicooneopcmkginofpcmgleeplobcd","fcmjlicbblmgpoedaglfpdmiajjnfjdlklfoapdigokimnjfnboecnlejeklcifhoomlnmlfimmjdpfieamjnmmcklcflmjd","dnfkclagfkofamkdijjhhklenidoahjeoieaddohalfdbkjgfeojdonnnpbpnkofhafohinchffihnkmcdbhnfano","jajcnlbijmpkhmninjpdjlaiabdpeinep","lpffenbmipjalpmocceaegabghkkbldmaaef","hfnjdgjcllcepegpgebbdiod","blofdnemnlghmhnklnagnjdhhncbligogkmcankckkicohicfocenpdfojnkkbfaihbfkceclmnj","blkojdljgkfbgoocagophckjhhaedplcecjhni","bfbmhobnbpjipgnohnnggkodlnhnpdnnjjodjjhjpoiblenkmmjfn","dakooapcaocdjjlohkhodebfljekmohmhaajabfmfpkmgenpcgejdmbpfhdmjcndidgnckejn","mcdplfipobaabeljedjjgffgibkjkfhcknlelcjploff","hfkkkgc","bckkahmfgpmllpjlegffdhmamighjeejfeibomlcflnf","hdlfkfnncgfggofkhbnnoogdhcjbmiecemdhblmaclcjjhfkd","hlleonkggomlodjiicahjpacmfmnjfhefghfjfjjhmollnmceckfl","fikabchalojpfe","eabebmiboflaoeilplfgbodlnpdjdiigcchpimdmgmimfdallmcig","piaaepcaceeiiejnliffickdbjnpbfggbdlcjcbggmbfegohjnnemkbjiaamcnplelnmlfjcab","olaganiohokddaakddildkphfmohabaneglhkapeeefkjdcb","obknlbdepjhofdgpjmbiefollhjdmkcgiembmcejbekalcdfpmdmpedblmodhkgmdnneheegkebc","fbelnnohpboamjkbddhlbcdllnlkgllkafiionmipaafpeibf","cdmdiekekdfagofmfnffnclcfjajllhojglodmpiaffddknehallhoojhjmgjifeofmagdjfengmpohechphnkghdjhmnldh","bfjegjnfdeipaogfeifnnpgpbblfdc","poenmckimbpifflnjcnejemhjdifmibniogckajponoamnoldfefdoglmhlldicekiecnmomp","nbchhcmpbialmi","jdebllagcaidnkmbbadfmnjjhiondmphngmmdkjmbmfecfdhhggmllmnjicdokbiekbpmkebhhcjjbolcppnomldpckdfij","dbbjijglkgaomhphbfpaejiiknadcoaopo","gdcakpbpcpeebncijnldoigfnm","njkhafdm","hahieknapoaidphimlidackdnhhdcnlfhhahjfdkacbdfdfeeogeklcfmmlfeiamjfpmbaiolgcgoncandlcabahfmdk","iagkkbchfijjnjggeiipikldigbinhdoppcaldcbognoakidpppchhdknedhlfmgmgmkombekejdigiimoefmahmahhhgdcm","jkpkfmpgfknpicjkodpjhmfhiikgdifapoldfojbahpbjbgdhiookababepckambnc","afcaeklcpjhjfampafogehdpiianokcpclohciajpmbaplgfpkjnkallpkoghglaccnfhnllkinigchddaak","hmkbgninnnmebgaghblo","npfpcpfekkcmb","dchjgnnbbdhllkdihdcdpkjdjmhnamjpfjalnambcpfmlahocemncmhoockmgedlegcfjnomdo","mh","kbbibjkm","fiopkjgdgpodnkpiekggelkhblbkeaoekdfpomgmcijfchankfmffiacafkcnbpp","pcemmimjiipcaimpipmpachpjlnpmdoneiag","ceoeipfliflfjnmpkngcoidgjicpapfaogiegfbhgpflnbjbgpencgaopmepkmfnkkjblphcgabbincgajfgelapmhjloefpogkpp","clockpjegiikjgkgjofgdgbjejknn","kjkjklbhfdmjmhnpmjoehniigbmofjmbmjkfmcahpgabamahpmimgicbfoemfomgdifoajmlnjbpbdfcilcidibhejkkbbhe","egkjneklne","aohokpnbnjchkkfipbfpjcbmnpebdklngnmfjaj","fhcnhadlelgajengoocmcjfmglpanhiciffmikjjgiboblmcbfomkdlkhpeoidfgemhccpogimlnpdemfia","jbemhdfkcoldoanpmedafkbpmnnfmhdmlncciojcmecoglahffmgkhgpofeegoebdnlfpebgapbflcma","hfhbipcidfdfgbhhmahnfgpliagmolhhfbmcjfgnhkdkale","nllcogabcbbfggkknkjimmbdlfinamdifcbgoffhekkhpfflpfnleccapgcepgankpnblofmphplpnomfdkdbcdhejp","dgpjgjnagacjfhlkhnmpfbhcplfehoolafmpieoh","mcjhhgajmclkoiobmgaaellbekaadlkopgbkobmmipeollfcjgo","lhnlcgljdpcbcjmncpiojli","obcddnfdiogpchomf","kjhkbnpcphmpnpilkhbjmeohodcoonanlmniifpiiiipcegagnhpbpfadgo","cjbakbbjaikfjnbimkeifcoinhhkcogokknajeagmfkcldfijhhfapnnjnljnecknlgdmapnlhffdndahoj","hdpflnimifempccgjolbdbdalfaapfijpmjnkaedkgmbpanmilleeahmnpiipna","cpjkhblnleglklhhdolggpgfmgahhilhbjgdhegkkeppiibnif","cldhiemiaoeaahi","cnjbbeedhddcjcelhcmfnmfcmpo","piekkbklhnpokeeiidbhbcjfgmddkejhdhfcenabobmjleemneikgkjokmcikiemgjhdmjcni","lknlpnlnnck","hgooknomoahjpebbcnidnagdfghooihkhjmeadhbojodhfkgkcbgmcbfkeammfhnlpbmoggfcgbcmfllalal","jljohilkaekocjcfdmpjgcpbpolfobdpmojcpmphlpnedaheholbbpdnnfoibpacmjmgglboodfoldicnjmodcipa","colgmamhgjeckgiiehibkipdl","afiljflhejeanlimdhcicfebapebcfefchdadfchfklcdgbkmagpkofpnphhhpbbpebkabdppocfbag"};
        test(str4,60, sizeof(str4)/sizeof(str4[0]));
       
        string str3[] = {"eae","ea","aaf","bda","fcf","dc","ac","ce","cefde","dabae"};
        test(str3, 15, sizeof(str3)/sizeof(str3[0]));

        string str1[]= {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
        test(str1, 16, sizeof(str1)/sizeof(str1[0]));

        string str[] = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
        test(str, 4, sizeof(str)/sizeof(str[0]));
          
        string str2[] = {"a", "aa", "aaa", "aaaa"};
        test(str2, 0, sizeof(str2)/sizeof(str2[0]));
}


