#!/usr/bin/env python3


from pycipher import Playfair
from math import exp
import ngram_score as ns
import random

ciphertext = 'UTAQBIHKRKNUWBRSESUKAERKHKRAKSNFIDNGDIRSOTUTASFKCLHIRTHSVSEIKBHLUTAPGQXUQAAPUTHMMRIASQRDYMGPUTKRSNGNABGSIDKDGPHLKEAEHPMDGDIXSHTFUSSHDHUSGTFSAFAEDIXHTYKODEIDHUNLNLFNSEDIZXDIRSGTPTCHIHZXDMSQRSGPAQSGKFHPIHMAFMTGBAMFAHKNHFKNGNKLCHKDGTRKHCEOSQUNRSIMHLDRGFGCSGXYNCPMQRRAEATGHKASKPVFRDUASQNCPMGNMHUVGSMEEQLEPTRSTEEMKNHAUNPACLESEQLDGSSPZAHIRAUBHYHPKHMHDHLCXHTYKRUTAEAHFNKNUMRAAMCGEHLCMASEPRHXIFAELCEDNLPAUTAERDHSGNPMEMRLDQHLQSYKUTUTSPPHUTHMYINCNRIXNCXSKBATASOHUTHMKRSNFNMIMAMSCGXUXHTYTRMLHPNKOSSIDQNGFMTGHKEAMFXHTYTGFMGXZRSERWHDKBNGIDHXHDNPHDXHQDHAAYDQBSDQDICLHIRAOSSILCNKRAEHUTAEAQGSRDMFGNINGKGPKNMHOMRFNCUXGTYUXUKYHLUNNKRSOTAZAEWGPHXSNSSHWSHUIBQBDHMIRSIUIBGPAKHDPKHPGTHEDIUSDRNCSBNOAMCGESIDNGRSRCHZLHUTTGPNCQASXUGBHURADHGXASEHUTHMZSRSZAOSSIDQKNPRUTAEKBHLEAFSNVNGGVNGSQSHSPVFKRWSGSMDLHIDNGLCOSSINGUTHMSWFSRKNGDMKRWSZAEAMIRSKXRQNKTNEMYSDIDHHURAHSDAGMPHSHHAIFGVAMGPFHPRGENPESKDWSDLSEDQUTAHNCSBAHHLKZSHSHKNXHQDMILCTGMIRSUNRAVIHMUSDQUSSESFDHABGSUSSESFDHHIRAEAHCNMLCNCSYGSTINPHDRAERSHQRHPVMIREAHMAEUTHLUTSZGSTIRSKXHZSFSUNGIHBYXUDQTGWSNVRPRQAQGSAZDMSPLRDAKOSZNCPMMFCHSPBHHAALAHYGLNRKGPGENPESTVTGPRZHSBKRAHNGSPUMRAVMWLIBDHKOSHKNYSDIHDRAHRGSDHHKHAAVEAGEPKBUTGPLSGRIMFRKOUHDRTRKHSPHZHSBKRDQMYGSQSMQSGIAASGMIXUTHQHCMAZARTFOSZSHCLHIESLHUKFHNVVBGSIHHLVSHKRAAMGPFHPRLCUSGKQSCLHIRAHSDAEASHNGUTHMUTEAAPRPPRIESFAHSEDENLFNSEKLEAGESQKRAPWRMHDHMIRAGEGCPAKDHKSOIBDHSHNCSBDESGRIMFUTHMXSHPWSDLMGDQHLQDZHUBDHKZMGOLSGTQQSSHNCDNXUHLHZSFKUNLWGBMKHKSBHQSMBWGXTMLHPAZAEKPPHUTKRTBIRRZNCKNIHGBKNGXNCSGXOUTDQKRWSZAIGLCSNXKPKGKIDHSEAZAAMIDNGUTHMVMEHBHLEHWAHHLGYHPAQDIGCMHTGDQYGQRTGNINOTESOKNKPDIUTDESEMHCGXUHRGSDHHKVSRKCHMHGTOUHPIDZAKNQDKLOHIHHMAHTDNVHLTZHDAEKDPHSVTGPHABBRBHAHSNOKSHAPBADESGTQBKGPGENPESKDHURAQOSGRIMFKDGPAMGPFHPRUTDEBHKRKXMGOGNKHDRSUNRAGENPESKDHONKGESQKRAPVRHAAVEAGEPKBUTGPLSGRIMFQBKXMGOLSGTQQSSHAPBADESGTQBKGPGENPESKIRTHAHUIGKRTFUSKNNOSEPRKNYKLHGEDYRQXUDIQDKLOHIHHMAHUTHDSQTHDBQHHLTESHKXGKDLGSMHHUGENLAEIDAHUTHMTGHZMISWLKLOHDADWRKNIGUTKRGENPESKFHLQRASRKGVYSDIDHGUVRGNUTAEGENPESKIRTEOSGRIMFFSOUNGMHTGHLSEYBIHSEVRKLXHKNQAWUAHRCRLLRPRUTHMYKNVQREAGEPKBUDQMANGOYDITURAFMTGMAPNIBUTKDHURAHZMFLOHZZAHURAWSTVHPIDHEDESGTQQSTZ'

class Key(object):
    def __init__(self, s='TESINGABCDFHKLMOPQRUVWXYZ'):
        self.key = list(s)

    def swap2letters(self):
        i = random.randrange(25)
        j = random.randrange(25)
        new_key = self.key[:]
        new_key[i], new_key[j] = self.key[j], self.key[i]
        return ''.join(new_key)

    def swap2rows(self):
        i = random.randrange(5)
        j = random.randrange(5)
        new_key = self.key[:]
        for k in range(5):
            new_key[i * 5 + k] = self.key[j * 5 + k]
            new_key[j * 5 + k] = self.key[i * 5 + k]

        return ''.join(new_key)



    def swap2cols(self):
        i = random.randrange(5)
        j = random.randrange(5)
        new_key = self.key[:]
        for k in range(5):
            new_key[k * 5 + i] = self.key[k * 5 + j]
            new_key[k * 5 + j] = self.key[k * 5 + i]

        return ''.join(new_key)

    def reverse(self):
        new_key = self.key[:]
        for i in range(25):
            new_key[i] = self.key[24 - i]

        return ''.join(new_key)


    def getNewKey(self):
        i = random.randrange(50)
        if(i == 0):
            return self.swap2rows()
        if(i == 1):
            return self.swap2cols()
        if(i == 2):
            return self.reverse()

        return self.swap2letters()

    def setKey(self, s):
        self.key = list(s)

key = Key()
fitness = ns.ngram_score('quadgrams.txt')
best_score = -20000.0
max_score = -20000.0
best_txt = ""
max_txt = ""
best_key = ""
max_key = ""
for i in range(50):
    T = (50.0 - i) / 5
    for j in range(10000):
        new_key = key.getNewKey()
        decrypted_txt = Playfair(key=new_key).decipher(ciphertext)
        the_score = fitness.score(decrypted_txt)
        dF = the_score - max_score
        if (dF >= 0):
            max_score = the_score
            max_key = new_key
            key.setKey(new_key)
            max_txt = decrypted_txt
        elif(T > 0):
            prob = exp(dF / T)
            if(prob > 1.0 * random.randrange(10)/10):
                key.setKey(new_key)
                max_key = new_key
                max_txt = decrypted_txt
                max_score = the_score

        # keep track of best score we have seen so far
        if(max_score > best_score):
            best_score = max_score
            best_txt = max_txt
            best_key = max_key
            print("Current Best: {}\n{}".format(best_key, best_txt))

print("\nWith enough luck, you should be able to decrypt, and get the answer THEFIRSTSIXTYCHARACTERSISTHESOLUTIONITHANKTHEACMFORTHISAWARD")
