using namespace ci;
using namespace ci::app;
using namespace std;

class Modes {
public:
    vector<int>         lyd_aug();
    vector<int>         lyd();
    vector<int>         ion();
    vector<int>         mix_SharpFour();
    vector<int>         mix();
    vector<int>         mix_FlatSix();
    vector<int>         mel_Min();
    vector<int>         dor();
    vector<int>         aeo();
    vector<int>         aeo_FlatFive();
    vector<int>         phr_NaturalSix();
    vector<int>         phr();
    vector<int>         loc();
    vector<int>         loc_FlatFour();
    
    vector<int>         getSus2_lyd_aug();
    vector<int>         getSus2_lyd();
    vector<int>         getSus2_ion();
    vector<int>         getSus2_mix_SharpFour();
    vector<int>         getSus2_mix();
    vector<int>         getSus2_mix_FlatSix();
    vector<int>         getSus2_mel_Min();
    vector<int>         getSus2_dor();
    vector<int>         getSus2_aeo();
    vector<int>         getSus2_aeo_FlatFive();
    vector<int>         getSus2_phr_NaturalSix();
    vector<int>         getSus2_phr();
    vector<int>         getSus2_loc();
    vector<int>         getSus2_loc_FlatFour();
    
    vector<int>         getMaj_lyd_aug();
    vector<int>         getMaj_lyd();
    vector<int>         getMaj_ion();
    vector<int>         getMaj_mix_SharpFour();
    vector<int>         getMaj_mix();
    vector<int>         getMaj_mix_FlatSix();
    vector<int>         getMaj_mel_Min();
    vector<int>         getMaj_dor();
    vector<int>         getMaj_aeo();
    vector<int>         getMaj_aeo_FlatFive();
    vector<int>         getMaj_phr_NaturalSix();
    vector<int>         getMaj_phr();
    vector<int>         getMaj_loc();
    vector<int>         getMaj_loc_FlatFour();

    vector<int>         getMin_lyd_aug();
    vector<int>         getMin_lyd();
    vector<int>         getMin_ion();
    vector<int>         getMin_mix_SharpFour();
    vector<int>         getMin_mix();
    vector<int>         getMin_mix_FlatSix();
    vector<int>         getMin_mel_Min();
    vector<int>         getMin_dor();
    vector<int>         getMin_aeo();
    vector<int>         getMin_aeo_FlatFive();
    vector<int>         getMin_phr_NaturalSix();
    vector<int>         getMin_phr();
    vector<int>         getMin_loc();
    vector<int>         getMin_loc_FlatFour();

    vector<int>         getThreeFour_lyd_aug();
    vector<int>         getThreeFour_lyd();
    vector<int>         getThreeFour_ion();
    vector<int>         getThreeFour_mix_SharpFour();
    vector<int>         getThreeFour_mix();
    vector<int>         getThreeFour_mix_FlatSix();
    vector<int>         getThreeFour_mel_Min();
    vector<int>         getThreeFour_dor();
    vector<int>         getThreeFour_aeo();
    vector<int>         getThreeFour_aeo_FlatFive();
    vector<int>         getThreeFour_phr_NaturalSix();
    vector<int>         getThreeFour_phr();
    vector<int>         getThreeFour_loc();
    vector<int>         getThreeFour_loc_FlatFour();
    
    vector<int>         getFiveSix_lyd_aug();
    vector<int>         getFiveSix_lyd();
    vector<int>         getFiveSix_ion();
    vector<int>         getFiveSix_mix_SharpFour();
    vector<int>         getFiveSix_mix();
    vector<int>         getFiveSix_mix_FlatSix();
    vector<int>         getFiveSix_mel_Min();
    vector<int>         getFiveSix_dor();
    vector<int>         getFiveSix_aeo();
    vector<int>         getFiveSix_aeo_FlatFive();
    vector<int>         getFiveSix_phr_NaturalSix();
    vector<int>         getFiveSix_phr();
    vector<int>         getFiveSix_loc();
    vector<int>         getFiveSix_loc_FlatFour();
    
    vector<int>         getSixFive_lyd_aug();
    vector<int>         getSixFive_lyd();
    vector<int>         getSixFive_ion();
    vector<int>         getSixFive_mix_SharpFour();
    vector<int>         getSixFive_mix();
    vector<int>         getSixFive_mel_Min();
    vector<int>         getSixFive_dor();
    vector<int>         getSixFive_aeo();
    vector<int>         getSixFive_aeo_FlatFive();
    vector<int>         getSixFive_phr_NaturalSix();
    vector<int>         getSixFive_phr();
    vector<int>         getSixFive_loc();
    vector<int>         getSixFive_loc_FlatFour();

};

//♯ ♭ ♮

vector<int> Modes::lyd_aug(){
    vector<int> notes;
    int mode[] = {0,2,4,6,8,9,11};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::lyd(){
    vector<int> notes;
    int mode[] = {0,2,4,6,7,9,11};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::ion(){
    vector<int> notes;
    int mode[] = {0,2,4,5,7,9,11};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::mix_SharpFour(){
    vector<int> notes;
    int mode[] = {0,2,4,6,7,9,10};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::mix(){
    vector<int> notes;
    int mode[] = {0,2,4,5,7,9,10};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::mix_FlatSix(){
    vector<int> notes;
    int mode[] = {0,2,4,5,7,8,10};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::mel_Min(){
    vector<int> notes;
    int mode[] = {0,2,3,5,7,9,11};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::dor(){
    vector<int> notes;
    int mode[] = {0,2,3,5,7,9,10};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::aeo(){
    vector<int> notes;
    int mode[] = {0,2,3,5,7,8,10};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::aeo_FlatFive(){
    vector<int> notes;
    int mode[] = {0,2,3,5,6,8,10};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::phr_NaturalSix(){
    vector<int> notes;
    int mode[] = {0,1,3,5,7,9,10};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::phr(){
    vector<int> notes;
    int mode[] = {0,1,3,5,7,8,10};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::loc(){
    vector<int> notes;
    int mode[] = {0,1,3,5,6,8,10};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::loc_FlatFour(){
    vector<int> notes;
    int mode[] = {0,1,3,4,6,8,10};
    notes.assign (mode,mode+7);
    return notes;
}

//--------------------------------
vector<int> Modes::getSus2_lyd(){
    vector<int> notes;
    int mode[] = {0,1,2,4,5};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getSus2_ion(){
    vector<int> notes;
    int mode[] = {0,1,3,4,5};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getSus2_mix(){
    vector<int> notes;
    int mode[] = {0,1,3,4,6};
        notes.assign (mode,mode+7);
        return notes;
    }

vector<int> Modes::getSus2_mix_FlatSix(){
    vector<int> notes;
    int mode[] = {0,3,6};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getSus2_dor(){
    vector<int> notes;
    int mode[] = {0,2,3,4,7};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getSus2_phr(){
    vector<int> notes;
    int mode[] = {1,2,3,5,6};
    notes.assign (mode,mode+7);
    return notes;
}

//--------------------------------
vector<int> Modes::getMaj_lyd(){
    vector<int> notes;
    int mode[] = {0,2,4};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getMaj_ion(){
    vector<int> notes;
    int mode[] = {0,3,4};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getMaj_mix(){
    vector<int> notes;
    int mode[] = {0,3,6};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getMaj_mix_FlatSix(){
    vector<int> notes;
    int mode[] = {0,6};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getMaj_dor(){
    vector<int> notes;
    int mode[] = {2,5,6};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getMaj_phr(){
    vector<int> notes;
    int mode[] = {1,3,5};
    notes.assign (mode,mode+7);
    return notes;
}

//--------------------------------
vector<int> Modes::getMin_lyd(){
    vector<int> notes;
    int mode[] = {0,2,4};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getMin_ion(){
    vector<int> notes;
    int mode[] = {0,3,4};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getMin_mix(){
    vector<int> notes;
    int mode[] = {0,3,6};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getMin_mix_FlatSix(){
    vector<int> notes;
    int mode[] = {0,6};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getMin_dor(){
    vector<int> notes;
    int mode[] = {2,5,6};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getMin_phr(){
    vector<int> notes;
    int mode[] = {1,3,5};
    notes.assign (mode,mode+7);
    return notes;
}

//--------------------------------
vector<int> Modes::getThreeFour_lyd(){
    vector<int> notes;
    int mode[] = {1,4};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getThreeFour_ion(){
    vector<int> notes;
    int mode[] = {0,4};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getThreeFour_mix(){
    vector<int> notes;
    int mode[] = {0,3};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getThreeFour_mix_FlatSix(){
    vector<int> notes;
    int mode[] = {0};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getThreeFour_dor(){
    vector<int> notes;
    int mode[] = {3,6};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getThreeFour_phr(){
    vector<int> notes;
    int mode[] = {3,5};
    notes.assign (mode,mode+7);
    return notes;
}

//--------------------------------
vector<int> Modes::getFiveSix_lyd(){
    vector<int> notes;
    int mode[] = {3};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getFiveSix_ion(){
    vector<int> notes;
    int mode[] = {0};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getFiveSix_mix(){
    vector<int> notes;
    int mode[] = {3};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getFiveSix_mix_FlatSix(){
    vector<int> notes;
    int mode[] = {3,5};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getFiveSix_dor(){
    vector<int> notes;
    int mode[] = {6};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getFiveSix_phr(){
    vector<int> notes;
    int mode[] = {5};
    notes.assign (mode,mode+7);
    return notes;
}

//--------------------------------
vector<int> Modes::getSixFive_lyd(){
    vector<int> notes;
    int mode[] = {0};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getSixFive_ion(){
    vector<int> notes;
    int mode[] = {3};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getSixFive_mix(){
    vector<int> notes;
    int mode[] = {6};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getSixFive_dor(){
    vector<int> notes;
    int mode[] = {2};
    notes.assign (mode,mode+7);
    return notes;
}

vector<int> Modes::getSixFive_phr(){
    vector<int> notes;
    int mode[] = {1};
    notes.assign (mode,mode+7);
    return notes;
}


