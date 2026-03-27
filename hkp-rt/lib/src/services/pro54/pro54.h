#pragma once 

#include <cstdint>
#include <cmath>
#include <cassert>
#include <string>
#include <cstring>
#include <array>
#include <iostream>
#include <map>

//==============================================================================
/// Auto-generated C++ class for the 'Pro54' processor
///

struct Pro54
{
    Pro54() = default;
    ~Pro54() = default;

    static constexpr std::string_view name = "Pro54";

    //==============================================================================
    using EndpointHandle = uint32_t;

    enum class EndpointType
    {
        stream,
        event,
        value
    };

    struct EndpointInfo
    {
        uint32_t handle;
        const char* name;
        EndpointType endpointType;
    };

    //==============================================================================
    static constexpr uint32_t numInputEndpoints  = 76;
    static constexpr uint32_t numOutputEndpoints = 1;

    static constexpr uint32_t maxFramesPerBlock  = 512;
    static constexpr uint32_t eventBufferSize    = 32;
    static constexpr uint32_t maxOutputEventSize = 0;
    static constexpr double   latency = 0.000000;

    enum class EndpointHandles
    {
        eventIn      = 1 ,
        externalIn   = 2 ,
        PolyModFilterEnv        = 3 ,
        PolyModOscB  = 4 ,
        PolyModFreqA = 5 ,
        PolyModPWA   = 6 ,
        PolyModFilt  = 7 ,
        OscAFreq     = 8 ,
        OscASaw      = 9 ,
        OscAPulse    = 10,
        OscAPW       = 11,
        OscASync     = 12,
        MixerOscALevel          = 13,
        MixerOscBLevel          = 14,
        MixerNoiseLevel         = 15,
        ExternalInputLevel      = 16,
        FilterCutoff = 17,
        FilterResonance         = 18,
        FilterEnvAmt = 19,
        FilterKeyboardTracking  = 20,
        FilterAttack = 21,
        FilterDecay  = 22,
        FilterSustain= 23,
        FilterRelease= 24,
        DelayTime    = 25,
        DelaySpread  = 26,
        DelayDepth   = 27,
        DelayRate    = 28,
        DelayFeedback= 29,
        DelayHiCut   = 30,
        DelayLoCut   = 31,
        DelayINV     = 32,
        DelayON      = 33,
        DelayWet     = 34,
        DelaySync    = 35,
        DelayMidi    = 36,
        LfoMidiSync  = 37,
        LfoFrequency = 38,
        LfoShapeSaw  = 39,
        LfoShapeTri  = 40,
        LfoShapePulse= 41,
        OscBFreq     = 42,
        OscBFreqFine = 43,
        OscBShapeSaw = 44,
        OscBShapeTri = 45,
        OscBShapePulse          = 46,
        OscBPWAmount = 47,
        OscBSubOsc   = 48,
        OscBKKeyboardTracking   = 49,
        WheelModulationLfoNoise = 50,
        WheelModulationFreqOscA = 51,
        WheelModulationFreqOscB = 52,
        WheelModulationPWA      = 53,
        WheelModulationPWB      = 54,
        WheelModulationFilter   = 55,
        Glide        = 56,
        Unison       = 57,
        AmplifierAttack         = 58,
        AmplifierDecay          = 59,
        AmplifierSustain        = 60,
        AmplifierRelease        = 61,
        Release      = 62,
        Velocity     = 63,
        Repeat       = 64,
        Drone        = 65,
        FilterHPF    = 66,
        FilterInvertEnv         = 67,
        Analog       = 68,
        MasterTune   = 69,
        Volume       = 70,
        ModWheel     = 71,
        PitchBend    = 72,
        FilterVersion= 73,
        ActiveVoices = 74,
        TestTone     = 75,
        midiIn       = 76,
        out          = 77
    };

    static constexpr uint32_t getEndpointHandleForName (std::string_view endpointName)
    {
        if (endpointName == "eventIn")       return static_cast<uint32_t> (EndpointHandles::eventIn);
        if (endpointName == "externalIn")    return static_cast<uint32_t> (EndpointHandles::externalIn);
        if (endpointName == "PolyModFilterEnv")         return static_cast<uint32_t> (EndpointHandles::PolyModFilterEnv);
        if (endpointName == "PolyModOscB")   return static_cast<uint32_t> (EndpointHandles::PolyModOscB);
        if (endpointName == "PolyModFreqA")  return static_cast<uint32_t> (EndpointHandles::PolyModFreqA);
        if (endpointName == "PolyModPWA")    return static_cast<uint32_t> (EndpointHandles::PolyModPWA);
        if (endpointName == "PolyModFilt")   return static_cast<uint32_t> (EndpointHandles::PolyModFilt);
        if (endpointName == "OscAFreq")      return static_cast<uint32_t> (EndpointHandles::OscAFreq);
        if (endpointName == "OscASaw")       return static_cast<uint32_t> (EndpointHandles::OscASaw);
        if (endpointName == "OscAPulse")     return static_cast<uint32_t> (EndpointHandles::OscAPulse);
        if (endpointName == "OscAPW")        return static_cast<uint32_t> (EndpointHandles::OscAPW);
        if (endpointName == "OscASync")      return static_cast<uint32_t> (EndpointHandles::OscASync);
        if (endpointName == "MixerOscALevel")return static_cast<uint32_t> (EndpointHandles::MixerOscALevel);
        if (endpointName == "MixerOscBLevel")return static_cast<uint32_t> (EndpointHandles::MixerOscBLevel);
        if (endpointName == "MixerNoiseLevel")          return static_cast<uint32_t> (EndpointHandles::MixerNoiseLevel);
        if (endpointName == "ExternalInputLevel")       return static_cast<uint32_t> (EndpointHandles::ExternalInputLevel);
        if (endpointName == "FilterCutoff")  return static_cast<uint32_t> (EndpointHandles::FilterCutoff);
        if (endpointName == "FilterResonance")          return static_cast<uint32_t> (EndpointHandles::FilterResonance);
        if (endpointName == "FilterEnvAmt")  return static_cast<uint32_t> (EndpointHandles::FilterEnvAmt);
        if (endpointName == "FilterKeyboardTracking")   return static_cast<uint32_t> (EndpointHandles::FilterKeyboardTracking);
        if (endpointName == "FilterAttack")  return static_cast<uint32_t> (EndpointHandles::FilterAttack);
        if (endpointName == "FilterDecay")   return static_cast<uint32_t> (EndpointHandles::FilterDecay);
        if (endpointName == "FilterSustain") return static_cast<uint32_t> (EndpointHandles::FilterSustain);
        if (endpointName == "FilterRelease") return static_cast<uint32_t> (EndpointHandles::FilterRelease);
        if (endpointName == "DelayTime")     return static_cast<uint32_t> (EndpointHandles::DelayTime);
        if (endpointName == "DelaySpread")   return static_cast<uint32_t> (EndpointHandles::DelaySpread);
        if (endpointName == "DelayDepth")    return static_cast<uint32_t> (EndpointHandles::DelayDepth);
        if (endpointName == "DelayRate")     return static_cast<uint32_t> (EndpointHandles::DelayRate);
        if (endpointName == "DelayFeedback") return static_cast<uint32_t> (EndpointHandles::DelayFeedback);
        if (endpointName == "DelayHiCut")    return static_cast<uint32_t> (EndpointHandles::DelayHiCut);
        if (endpointName == "DelayLoCut")    return static_cast<uint32_t> (EndpointHandles::DelayLoCut);
        if (endpointName == "DelayINV")      return static_cast<uint32_t> (EndpointHandles::DelayINV);
        if (endpointName == "DelayON")       return static_cast<uint32_t> (EndpointHandles::DelayON);
        if (endpointName == "DelayWet")      return static_cast<uint32_t> (EndpointHandles::DelayWet);
        if (endpointName == "DelaySync")     return static_cast<uint32_t> (EndpointHandles::DelaySync);
        if (endpointName == "DelayMidi")     return static_cast<uint32_t> (EndpointHandles::DelayMidi);
        if (endpointName == "LfoMidiSync")   return static_cast<uint32_t> (EndpointHandles::LfoMidiSync);
        if (endpointName == "LfoFrequency")  return static_cast<uint32_t> (EndpointHandles::LfoFrequency);
        if (endpointName == "LfoShapeSaw")   return static_cast<uint32_t> (EndpointHandles::LfoShapeSaw);
        if (endpointName == "LfoShapeTri")   return static_cast<uint32_t> (EndpointHandles::LfoShapeTri);
        if (endpointName == "LfoShapePulse") return static_cast<uint32_t> (EndpointHandles::LfoShapePulse);
        if (endpointName == "OscBFreq")      return static_cast<uint32_t> (EndpointHandles::OscBFreq);
        if (endpointName == "OscBFreqFine")  return static_cast<uint32_t> (EndpointHandles::OscBFreqFine);
        if (endpointName == "OscBShapeSaw")  return static_cast<uint32_t> (EndpointHandles::OscBShapeSaw);
        if (endpointName == "OscBShapeTri")  return static_cast<uint32_t> (EndpointHandles::OscBShapeTri);
        if (endpointName == "OscBShapePulse")return static_cast<uint32_t> (EndpointHandles::OscBShapePulse);
        if (endpointName == "OscBPWAmount")  return static_cast<uint32_t> (EndpointHandles::OscBPWAmount);
        if (endpointName == "OscBSubOsc")    return static_cast<uint32_t> (EndpointHandles::OscBSubOsc);
        if (endpointName == "OscBKKeyboardTracking")    return static_cast<uint32_t> (EndpointHandles::OscBKKeyboardTracking);
        if (endpointName == "WheelModulationLfoNoise")  return static_cast<uint32_t> (EndpointHandles::WheelModulationLfoNoise);
        if (endpointName == "WheelModulationFreqOscA")  return static_cast<uint32_t> (EndpointHandles::WheelModulationFreqOscA);
        if (endpointName == "WheelModulationFreqOscB")  return static_cast<uint32_t> (EndpointHandles::WheelModulationFreqOscB);
        if (endpointName == "WheelModulationPWA")       return static_cast<uint32_t> (EndpointHandles::WheelModulationPWA);
        if (endpointName == "WheelModulationPWB")       return static_cast<uint32_t> (EndpointHandles::WheelModulationPWB);
        if (endpointName == "WheelModulationFilter")    return static_cast<uint32_t> (EndpointHandles::WheelModulationFilter);
        if (endpointName == "Glide")         return static_cast<uint32_t> (EndpointHandles::Glide);
        if (endpointName == "Unison")        return static_cast<uint32_t> (EndpointHandles::Unison);
        if (endpointName == "AmplifierAttack")          return static_cast<uint32_t> (EndpointHandles::AmplifierAttack);
        if (endpointName == "AmplifierDecay")return static_cast<uint32_t> (EndpointHandles::AmplifierDecay);
        if (endpointName == "AmplifierSustain")         return static_cast<uint32_t> (EndpointHandles::AmplifierSustain);
        if (endpointName == "AmplifierRelease")         return static_cast<uint32_t> (EndpointHandles::AmplifierRelease);
        if (endpointName == "Release")       return static_cast<uint32_t> (EndpointHandles::Release);
        if (endpointName == "Velocity")      return static_cast<uint32_t> (EndpointHandles::Velocity);
        if (endpointName == "Repeat")        return static_cast<uint32_t> (EndpointHandles::Repeat);
        if (endpointName == "Drone")         return static_cast<uint32_t> (EndpointHandles::Drone);
        if (endpointName == "FilterHPF")     return static_cast<uint32_t> (EndpointHandles::FilterHPF);
        if (endpointName == "FilterInvertEnv")          return static_cast<uint32_t> (EndpointHandles::FilterInvertEnv);
        if (endpointName == "Analog")        return static_cast<uint32_t> (EndpointHandles::Analog);
        if (endpointName == "MasterTune")    return static_cast<uint32_t> (EndpointHandles::MasterTune);
        if (endpointName == "Volume")        return static_cast<uint32_t> (EndpointHandles::Volume);
        if (endpointName == "ModWheel")      return static_cast<uint32_t> (EndpointHandles::ModWheel);
        if (endpointName == "PitchBend")     return static_cast<uint32_t> (EndpointHandles::PitchBend);
        if (endpointName == "FilterVersion") return static_cast<uint32_t> (EndpointHandles::FilterVersion);
        if (endpointName == "ActiveVoices")  return static_cast<uint32_t> (EndpointHandles::ActiveVoices);
        if (endpointName == "TestTone")      return static_cast<uint32_t> (EndpointHandles::TestTone);
        if (endpointName == "midiIn")        return static_cast<uint32_t> (EndpointHandles::midiIn);
        if (endpointName == "out")return static_cast<uint32_t> (EndpointHandles::out);
        return 0;
    }

    static constexpr EndpointInfo inputEndpoints[] =
    {
        { 1,   "eventIn",       EndpointType::event  },
        { 2,   "externalIn",    EndpointType::stream },
        { 3,   "PolyModFilterEnv",         EndpointType::event  },
        { 4,   "PolyModOscB",   EndpointType::event  },
        { 5,   "PolyModFreqA",  EndpointType::event  },
        { 6,   "PolyModPWA",    EndpointType::event  },
        { 7,   "PolyModFilt",   EndpointType::event  },
        { 8,   "OscAFreq",      EndpointType::event  },
        { 9,   "OscASaw",       EndpointType::event  },
        { 10,  "OscAPulse",     EndpointType::event  },
        { 11,  "OscAPW",        EndpointType::event  },
        { 12,  "OscASync",      EndpointType::event  },
        { 13,  "MixerOscALevel",EndpointType::event  },
        { 14,  "MixerOscBLevel",EndpointType::event  },
        { 15,  "MixerNoiseLevel",          EndpointType::event  },
        { 16,  "ExternalInputLevel",       EndpointType::event  },
        { 17,  "FilterCutoff",  EndpointType::event  },
        { 18,  "FilterResonance",          EndpointType::event  },
        { 19,  "FilterEnvAmt",  EndpointType::event  },
        { 20,  "FilterKeyboardTracking",   EndpointType::event  },
        { 21,  "FilterAttack",  EndpointType::event  },
        { 22,  "FilterDecay",   EndpointType::event  },
        { 23,  "FilterSustain", EndpointType::event  },
        { 24,  "FilterRelease", EndpointType::event  },
        { 25,  "DelayTime",     EndpointType::event  },
        { 26,  "DelaySpread",   EndpointType::event  },
        { 27,  "DelayDepth",    EndpointType::event  },
        { 28,  "DelayRate",     EndpointType::event  },
        { 29,  "DelayFeedback", EndpointType::event  },
        { 30,  "DelayHiCut",    EndpointType::event  },
        { 31,  "DelayLoCut",    EndpointType::event  },
        { 32,  "DelayINV",      EndpointType::event  },
        { 33,  "DelayON",       EndpointType::event  },
        { 34,  "DelayWet",      EndpointType::event  },
        { 35,  "DelaySync",     EndpointType::event  },
        { 36,  "DelayMidi",     EndpointType::event  },
        { 37,  "LfoMidiSync",   EndpointType::event  },
        { 38,  "LfoFrequency",  EndpointType::event  },
        { 39,  "LfoShapeSaw",   EndpointType::event  },
        { 40,  "LfoShapeTri",   EndpointType::event  },
        { 41,  "LfoShapePulse", EndpointType::event  },
        { 42,  "OscBFreq",      EndpointType::event  },
        { 43,  "OscBFreqFine",  EndpointType::event  },
        { 44,  "OscBShapeSaw",  EndpointType::event  },
        { 45,  "OscBShapeTri",  EndpointType::event  },
        { 46,  "OscBShapePulse",EndpointType::event  },
        { 47,  "OscBPWAmount",  EndpointType::event  },
        { 48,  "OscBSubOsc",    EndpointType::event  },
        { 49,  "OscBKKeyboardTracking",    EndpointType::event  },
        { 50,  "WheelModulationLfoNoise",  EndpointType::event  },
        { 51,  "WheelModulationFreqOscA",  EndpointType::event  },
        { 52,  "WheelModulationFreqOscB",  EndpointType::event  },
        { 53,  "WheelModulationPWA",       EndpointType::event  },
        { 54,  "WheelModulationPWB",       EndpointType::event  },
        { 55,  "WheelModulationFilter",    EndpointType::event  },
        { 56,  "Glide",         EndpointType::event  },
        { 57,  "Unison",        EndpointType::event  },
        { 58,  "AmplifierAttack",          EndpointType::event  },
        { 59,  "AmplifierDecay",EndpointType::event  },
        { 60,  "AmplifierSustain",         EndpointType::event  },
        { 61,  "AmplifierRelease",         EndpointType::event  },
        { 62,  "Release",       EndpointType::event  },
        { 63,  "Velocity",      EndpointType::event  },
        { 64,  "Repeat",        EndpointType::event  },
        { 65,  "Drone",         EndpointType::event  },
        { 66,  "FilterHPF",     EndpointType::event  },
        { 67,  "FilterInvertEnv",          EndpointType::event  },
        { 68,  "Analog",        EndpointType::event  },
        { 69,  "MasterTune",    EndpointType::event  },
        { 70,  "Volume",        EndpointType::event  },
        { 71,  "ModWheel",      EndpointType::event  },
        { 72,  "PitchBend",     EndpointType::event  },
        { 73,  "FilterVersion", EndpointType::event  },
        { 74,  "ActiveVoices",  EndpointType::event  },
        { 75,  "TestTone",      EndpointType::event  },
        { 76,  "midiIn",        EndpointType::event  }
    };

    static constexpr EndpointInfo outputEndpoints[] =
    {
        { 77,  "out",  EndpointType::stream }
    };

    //==============================================================================
    static constexpr uint32_t numAudioInputChannels  = 1;
    static constexpr uint32_t numAudioOutputChannels = 2;

    static constexpr std::array outputAudioStreams
    {
        outputEndpoints[0]
    };

    static constexpr std::array<EndpointInfo, 0> outputEvents {};

    static constexpr std::array<EndpointInfo, 0> outputMIDIEvents {};

    static constexpr std::array inputAudioStreams
    {
        inputEndpoints[1]
    };

    static constexpr std::array inputEvents
    {
        inputEndpoints[0],
        inputEndpoints[2],
        inputEndpoints[3],
        inputEndpoints[4],
        inputEndpoints[5],
        inputEndpoints[6],
        inputEndpoints[7],
        inputEndpoints[8],
        inputEndpoints[9],
        inputEndpoints[10],
        inputEndpoints[11],
        inputEndpoints[12],
        inputEndpoints[13],
        inputEndpoints[14],
        inputEndpoints[15],
        inputEndpoints[16],
        inputEndpoints[17],
        inputEndpoints[18],
        inputEndpoints[19],
        inputEndpoints[20],
        inputEndpoints[21],
        inputEndpoints[22],
        inputEndpoints[23],
        inputEndpoints[24],
        inputEndpoints[25],
        inputEndpoints[26],
        inputEndpoints[27],
        inputEndpoints[28],
        inputEndpoints[29],
        inputEndpoints[30],
        inputEndpoints[31],
        inputEndpoints[32],
        inputEndpoints[33],
        inputEndpoints[34],
        inputEndpoints[35],
        inputEndpoints[36],
        inputEndpoints[37],
        inputEndpoints[38],
        inputEndpoints[39],
        inputEndpoints[40],
        inputEndpoints[41],
        inputEndpoints[42],
        inputEndpoints[43],
        inputEndpoints[44],
        inputEndpoints[45],
        inputEndpoints[46],
        inputEndpoints[47],
        inputEndpoints[48],
        inputEndpoints[49],
        inputEndpoints[50],
        inputEndpoints[51],
        inputEndpoints[52],
        inputEndpoints[53],
        inputEndpoints[54],
        inputEndpoints[55],
        inputEndpoints[56],
        inputEndpoints[57],
        inputEndpoints[58],
        inputEndpoints[59],
        inputEndpoints[60],
        inputEndpoints[61],
        inputEndpoints[62],
        inputEndpoints[63],
        inputEndpoints[64],
        inputEndpoints[65],
        inputEndpoints[66],
        inputEndpoints[67],
        inputEndpoints[68],
        inputEndpoints[69],
        inputEndpoints[70],
        inputEndpoints[71],
        inputEndpoints[72],
        inputEndpoints[73],
        inputEndpoints[74],
        inputEndpoints[75]
    };

    static constexpr std::array inputMIDIEvents
    {
        inputEndpoints[75]
    };

    static constexpr std::array inputParameters
    {
        inputEndpoints[2],
        inputEndpoints[3],
        inputEndpoints[4],
        inputEndpoints[5],
        inputEndpoints[6],
        inputEndpoints[7],
        inputEndpoints[8],
        inputEndpoints[9],
        inputEndpoints[10],
        inputEndpoints[11],
        inputEndpoints[12],
        inputEndpoints[13],
        inputEndpoints[14],
        inputEndpoints[15],
        inputEndpoints[16],
        inputEndpoints[17],
        inputEndpoints[18],
        inputEndpoints[19],
        inputEndpoints[20],
        inputEndpoints[21],
        inputEndpoints[22],
        inputEndpoints[23],
        inputEndpoints[24],
        inputEndpoints[25],
        inputEndpoints[26],
        inputEndpoints[27],
        inputEndpoints[28],
        inputEndpoints[29],
        inputEndpoints[30],
        inputEndpoints[31],
        inputEndpoints[32],
        inputEndpoints[33],
        inputEndpoints[34],
        inputEndpoints[35],
        inputEndpoints[36],
        inputEndpoints[37],
        inputEndpoints[38],
        inputEndpoints[39],
        inputEndpoints[40],
        inputEndpoints[41],
        inputEndpoints[42],
        inputEndpoints[43],
        inputEndpoints[44],
        inputEndpoints[45],
        inputEndpoints[46],
        inputEndpoints[47],
        inputEndpoints[48],
        inputEndpoints[49],
        inputEndpoints[50],
        inputEndpoints[51],
        inputEndpoints[52],
        inputEndpoints[53],
        inputEndpoints[54],
        inputEndpoints[55],
        inputEndpoints[56],
        inputEndpoints[57],
        inputEndpoints[58],
        inputEndpoints[59],
        inputEndpoints[60],
        inputEndpoints[61],
        inputEndpoints[62],
        inputEndpoints[63],
        inputEndpoints[64],
        inputEndpoints[65],
        inputEndpoints[66],
        inputEndpoints[67],
        inputEndpoints[68],
        inputEndpoints[69],
        inputEndpoints[70],
        inputEndpoints[71],
        inputEndpoints[72],
        inputEndpoints[73],
        inputEndpoints[74]
    };

    static constexpr const char* programDetailsJSON = "{\n"
        "  \"mainProcessor\": \"Pro54\",\n"
        "  \"inputs\": [\n"
        "    {\n"
        "      \"endpointID\": \"eventIn\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataTypes\": [\n"
        "        {\n"
        "          \"type\": \"object\",\n"
        "          \"class\": \"NoteOn\",\n"
        "          \"members\": {\n"
        " \"channel\": {\n"
        "   \"type\": \"int32\"\n"
        " },\n"
        " \"pitch\": {\n"
        "   \"type\": \"float32\"\n"
        " },\n"
        " \"velocity\": {\n"
        "   \"type\": \"float32\"\n"
        " }\n"
        "          }\n"
        "        },\n"
        "        {\n"
        "          \"type\": \"object\",\n"
        "          \"class\": \"NoteOff\",\n"
        "          \"members\": {\n"
        " \"channel\": {\n"
        "   \"type\": \"int32\"\n"
        " },\n"
        " \"pitch\": {\n"
        "   \"type\": \"float32\"\n"
        " },\n"
        " \"velocity\": {\n"
        "   \"type\": \"float32\"\n"
        " }\n"
        "          }\n"
        "        },\n"
        "        {\n"
        "          \"type\": \"object\",\n"
        "          \"class\": \"PitchBend\",\n"
        "          \"members\": {\n"
        " \"channel\": {\n"
        "   \"type\": \"int32\"\n"
        " },\n"
        " \"bendSemitones\": {\n"
        "   \"type\": \"float32\"\n"
        " }\n"
        "          }\n"
        "        },\n"
        "        {\n"
        "          \"type\": \"object\",\n"
        "          \"class\": \"Control\",\n"
        "          \"members\": {\n"
        " \"channel\": {\n"
        "   \"type\": \"int32\"\n"
        " },\n"
        " \"control\": {\n"
        "   \"type\": \"int32\"\n"
        " },\n"
        " \"value\": {\n"
        "   \"type\": \"float32\"\n"
        " }\n"
        "          }\n"
        "        }\n"
        "      ]\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"externalIn\",\n"
        "      \"endpointType\": \"stream\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"External Audio In\"\n"
        "      },\n"
        "      \"purpose\": \"audio in\",\n"
        "      \"numAudioChannels\": 1\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"PolyModFilterEnv\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"PolyMod Source Filt Env\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 37.7953\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"PolyModOscB\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"PolyMod Source Osc B\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 50.3937\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"PolyModFreqA\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"PolyMod Dest Freq A\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 1,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"PolyModPWA\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"PolyMod Dest PWidth A\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"PolyModFilt\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"PolyMod Dest Filter\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"OscAFreq\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Oscillator A Frequency\",\n"
        "        \"unit\": \"st\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 63.7795\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"OscASaw\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Oscillator A Sawtooth\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 1,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"OscAPulse\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Oscillator A Pulse\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"OscAPW\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Oscillator A PulseWidth\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 19.685\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"OscASync\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Oscillator A Sync\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 1,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"MixerOscALevel\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Mixer Oscillator A\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 61.4173\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"MixerOscBLevel\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Mixer Oscillator B\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 100\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"MixerNoiseLevel\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Mixer Noise\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 0.0\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"ExternalInputLevel\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Mixer External Input\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 0.0\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"FilterCutoff\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Filter Cutoff\",\n"
        "        \"unit\": \"st\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 29.9213\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"FilterResonance\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Filter Resonance\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 29.1339\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"FilterEnvAmt\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Filter Envelope Amount\",\n"
        "        \"unit\": \"st\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 37.0079\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"FilterKeyboardTracking\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Filter Keyboard Follow\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 100\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"FilterAttack\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Filter Attack\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 0.0\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"FilterDecay\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Filter Decay\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 68.5039\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"FilterSustain\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Filter Sustain\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 0.0\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"FilterRelease\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Filter Release\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 65.3543\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"DelayTime\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Delay Effect Time\",\n"
        "        \"unit\": \"ms\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 68.5039\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"DelaySpread\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Delay Effect Spread\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 41.7323\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"DelayDepth\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Delay Effect Depth\",\n"
        "        \"unit\": \"ms\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 0.0\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"DelayRate\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Delay Effect Rate\",\n"
        "        \"unit\": \"Hz\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 0.0\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"DelayFeedback\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Delay Effect Feedback\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 26.7717\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"DelayHiCut\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Delay Effect High Cut\",\n"
        "        \"unit\": \"st\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 30.7087\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"DelayLoCut\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Delay Effect Low Cut\",\n"
        "        \"unit\": \"st\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 70.0787\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"DelayINV\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Delay Effect Invert\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"DelayON\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Delay Effect On\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 1,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"DelayWet\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Delay Effect Wet\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 20.4724\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"DelaySync\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Delay Effect Sync\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"DelayMidi\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Delay Effect MIDI Sync\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"LfoMidiSync\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"LFO MIDI Sync\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"LfoFrequency\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"LFO Frequency\",\n"
        "        \"unit\": \"Hz\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 73.2283\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"LfoShapeSaw\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"LFO Sawtooth\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"LfoShapeTri\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"LFO Triangle\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"LfoShapePulse\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"LFO Pulse\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 1,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"OscBFreq\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Oscillator B Frequency\",\n"
        "        \"unit\": \"st\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 25.1968\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"OscBFreqFine\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Oscillator B Freq Fine\",\n"
        "        \"unit\": \"ct\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 0.0\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"OscBShapeSaw\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Oscillator B Sawtooth\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"OscBShapeTri\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Oscillator B Triangle\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 1,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"OscBShapePulse\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Oscillator B Pulse\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"OscBPWAmount\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Oscillator B PulseWidth\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 11.0236\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"OscBSubOsc\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Oscillator B Low Freq\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"OscBKKeyboardTracking\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Oscillator B Key Follow\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 1,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"WheelModulationLfoNoise\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"WheelMod LFO-Noise Mix\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 0.0\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"WheelModulationFreqOscA\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"WheelMod Dest Freq A\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 1,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"WheelModulationFreqOscB\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"WheelMod Dest Freq B\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"WheelModulationPWA\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"WheelMod Dest PWidth A\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"WheelModulationPWB\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"WheelMod Dest PWidth B\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"WheelModulationFilter\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"WheelMod Dest Filter\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"Glide\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Glide Time\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 0.0\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"Unison\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Unisono Mode\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"AmplifierAttack\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Amplifier Attack\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 0.0\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"AmplifierDecay\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Amplifier Decay\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 61.4173\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"AmplifierSustain\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Amplifier Sustain\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 71.6535\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"AmplifierRelease\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Amplifier Release\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 37.7953\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"Release\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Release on/off\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 1,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"Velocity\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Velocity on/off\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 1,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"Repeat\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"LFO Envelope Trigger\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"Drone\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Amplifier Hold\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"FilterHPF\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Filter HPF-Mode\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"FilterInvertEnv\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Filter Envelope Invert\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"Analog\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Analog\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 33.0709\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"MasterTune\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Master Tune\",\n"
        "        \"unit\": \"ct\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 50\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"Volume\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Master Volume\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 100\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"ModWheel\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Modulation Wheel\",\n"
        "        \"unit\": \"%\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 0.0\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"PitchBend\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Pitch Bend\",\n"
        "        \"unit\": \"ct\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 100,\n"
        "        \"init\": 50\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"FilterVersion\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Filter Version\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Old|New|New AA\"\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"ActiveVoices\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Active Voices\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 1,\n"
        "        \"max\": 32,\n"
        "        \"init\": 5,\n"
        "        \"step\": 1\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"TestTone\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"float32\"\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Test Tone\",\n"
        "        \"unit\": \"\",\n"
        "        \"min\": 0.0,\n"
        "        \"max\": 1,\n"
        "        \"init\": 0.0,\n"
        "        \"text\": \"Off|On\",\n"
        "        \"boolean\": true\n"
        "      },\n"
        "      \"purpose\": \"parameter\"\n"
        "    },\n"
        "    {\n"
        "      \"endpointID\": \"midiIn\",\n"
        "      \"endpointType\": \"event\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"object\",\n"
        "        \"class\": \"Message\",\n"
        "        \"members\": {\n"
        "          \"message\": {\n"
        " \"type\": \"int32\"\n"
        "          }\n"
        "        }\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"MIDI In\"\n"
        "      },\n"
        "      \"purpose\": \"midi in\"\n"
        "    }\n"
        "  ],\n"
        "  \"outputs\": [\n"
        "    {\n"
        "      \"endpointID\": \"out\",\n"
        "      \"endpointType\": \"stream\",\n"
        "      \"dataType\": {\n"
        "        \"type\": \"vector\",\n"
        "        \"element\": {\n"
        "          \"type\": \"float32\"\n"
        "        },\n"
        "        \"size\": 2\n"
        "      },\n"
        "      \"annotation\": {\n"
        "        \"name\": \"Audio Out\"\n"
        "      },\n"
        "      \"purpose\": \"audio out\",\n"
        "      \"numAudioChannels\": 2\n"
        "    }\n"
        "  ]\n"
        "}";

    //==============================================================================
    struct intrinsics;

    using SizeType = int32_t;
    using IndexType = int32_t;
    using StringHandle = uint32_t;

    struct Null
    {
        template <typename AnyType> operator AnyType() const    { return {}; }
        Null operator[] (IndexType) const { return {}; }
    };

    //==============================================================================
    template <typename ElementType, SizeType numElements>
    struct Array
    {
        Array() = default;
        Array (Null) {}
        Array (const Array&) = default;

        template <typename ElementOrList>
        Array (const ElementOrList& value) noexcept
        {
 if constexpr (std::is_convertible<ElementOrList, ElementType>::value)
 {
     for (IndexType i = 0; i < numElements; ++i)
         this->elements[i] = static_cast<ElementType> (value);
 }
 else
 {
     for (IndexType i = 0; i < numElements; ++i)
         this->elements[i] = static_cast<ElementType> (value[i]);
 }
        }

        template <typename... Others>
        Array (ElementType e0, ElementType e1, Others... others) noexcept
        {
 this->elements[0] = static_cast<ElementType> (e0);
 this->elements[1] = static_cast<ElementType> (e1);

 if constexpr (numElements > 2)
 {
     const ElementType initialisers[] = { static_cast<ElementType> (others)... };

     for (size_t i = 0; i < sizeof...(others); ++i)
         this->elements[i + 2] = initialisers[i];
 }
        }

        Array (const ElementType* rawArray, size_t) noexcept
        {
 for (IndexType i = 0; i < numElements; ++i)
     this->elements[i] = rawArray[i];
        }

        Array& operator= (const Array&) noexcept = default;
        Array& operator= (Null) noexcept      { this->clear(); return *this; }

        template <typename ElementOrList>
        Array& operator= (const ElementOrList& value) noexcept
        {
 if constexpr (std::is_convertible<ElementOrList, ElementType>::value)
 {
     for (IndexType i = 0; i < numElements; ++i)
         this->elements[i] = static_cast<ElementType> (value);
 }
 else
 {
     for (IndexType i = 0; i < numElements; ++i)
         this->elements[i] = static_cast<ElementType> (value[i]);
 }
        }

        static constexpr SizeType size()   { return numElements; }

        const ElementType& operator[] (IndexType index) const noexcept      { return this->elements[index]; }
        ElementType& operator[] (IndexType index) noexcept       { return this->elements[index]; }

        void clear() noexcept
        {
 for (auto& element : elements)
     element = ElementType();
        }

        void clear (SizeType numElementsToClear) noexcept
        {
 for (SizeType i = 0; i < numElementsToClear; ++i)
     elements[i] = ElementType();
        }

        ElementType elements[numElements] = {};
    };

    //==============================================================================
    template <typename ElementType, SizeType numElements>
    struct Vector: public Array<ElementType, numElements>
    {
        Vector() = default;
        Vector (Null) {}

        template <typename ElementOrList>
        Vector (const ElementOrList& value) noexcept: Array<ElementType, numElements> (value) {}

        template <typename... Others>
        Vector (ElementType e0, ElementType e1, Others... others) noexcept: Array<ElementType, numElements> (e0, e1, others...) {}

        Vector (const ElementType* rawArray, size_t) noexcept: Array<ElementType, numElements> (rawArray, size_t()) {}

        template <typename ElementOrList>
        Vector& operator= (const ElementOrList& value) noexcept { return Array<ElementType, numElements>::operator= (value); }

        Vector& operator= (Null) noexcept { this->clear(); return *this; }

        operator ElementType() const noexcept
        {
 static_assert (numElements == 1);
 return this->elements[0];
        }

        constexpr auto operator!() const noexcept     { return performUnaryOp ([] (ElementType n) { return ! n; }); }
        constexpr auto operator~() const noexcept     { return performUnaryOp ([] (ElementType n) { return ~n; }); }
        constexpr auto operator-() const noexcept     { return performUnaryOp ([] (ElementType n) { return -n; }); }

        constexpr auto operator+ (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a + b; }); }
        constexpr auto operator- (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a - b; }); }
        constexpr auto operator* (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a * b; }); }
        constexpr auto operator/ (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return a / b; }); }
        constexpr auto operator% (const Vector& rhs) const noexcept   { return performBinaryOp (rhs, [] (ElementType a, ElementType b) { return intrinsics::modulo (a, b); }); }

        constexpr auto operator== (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a == b; }); }
        constexpr auto operator!= (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a != b; }); }
        constexpr auto operator<  (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a < b; }); }
        constexpr auto operator<= (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a <= b; }); }
        constexpr auto operator>  (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a > b; }); }
        constexpr auto operator>= (const Vector& rhs) const noexcept  { return performComparison (rhs, [] (ElementType a, ElementType b) { return a >= b; }); }

        template <typename Functor>
        constexpr Vector performUnaryOp (Functor&& f) const noexcept
        {
 Vector result;

 for (IndexType i = 0; i < numElements; ++i)
     result.elements[i] = f (this->elements[i]);

 return result;
        }

        template <typename Functor>
        constexpr Vector performBinaryOp (const Vector& rhs, Functor&& f) const noexcept
        {
 Vector result;

 for (IndexType i = 0; i < numElements; ++i)
     result.elements[i] = f (this->elements[i], rhs.elements[i]);

 return result;
        }

        template <typename Functor>
        constexpr Vector<bool, numElements> performComparison (const Vector& rhs, Functor&& f) const noexcept
        {
 Vector<bool, numElements> result;

 for (IndexType i = 0; i < numElements; ++i)
     result.elements[i] = f (this->elements[i], rhs.elements[i]);

 return result;
        }
    };

    //==============================================================================
    template <typename ElementType>
    struct Slice
    {
        Slice() = default;
        Slice (Null) {}
        Slice (ElementType* e, SizeType size) : elements (e), numElements (size) {}
        Slice (const Slice&) = default;
        Slice& operator= (const Slice&) = default;
        template <typename ArrayType> Slice (const ArrayType& a) : elements (const_cast<ArrayType&> (a).elements), numElements (a.size()) {}
        template <typename ArrayType> Slice (const ArrayType& a, SizeType offset, SizeType size) : elements (const_cast<ArrayType&> (a).elements + offset), numElements (size) {}

        constexpr SizeType size() const    { return numElements; }
        ElementType operator[] (IndexType index) const noexcept  { return numElements == 0 ? ElementType() : elements[index]; }
        ElementType& operator[] (IndexType index) noexcept       { return numElements == 0 ? emptyValue : elements[index]; }

        Slice slice (IndexType start, IndexType end) noexcept
        {
 if (numElements == 0) return {};
 if (start >= numElements) return {};

 return { elements + start, std::min (static_cast<SizeType> (end - start), numElements - start) };
        }

        ElementType* elements = nullptr;
        SizeType numElements = 0;

        static inline ElementType emptyValue {};
    };

    //==============================================================================
    #if __clang__
     #pragma clang diagnostic push
     #pragma clang diagnostic ignored "-Wunused-variable"
     #pragma clang diagnostic ignored "-Wunused-parameter"
     #pragma clang diagnostic ignored "-Wunused-label"

     #if __clang_major__ >= 14
      #pragma clang diagnostic ignored "-Wunused-but-set-variable"
     #endif

    #elif __GNUC__
     #pragma GCC diagnostic push
     #pragma GCC diagnostic ignored "-Wunused-variable"
     #pragma GCC diagnostic ignored "-Wunused-parameter"
     #pragma GCC diagnostic ignored "-Wunused-but-set-variable"
     #pragma GCC diagnostic ignored "-Wunused-label"
    #else
     #pragma warning (push, 0)
     #pragma warning (disable: 4702)
     #pragma warning (disable: 4706)
    #endif

    //==============================================================================
    struct _Engine_1_MonoSignals
    {
        float controlCount = {};
        int32_t knobSmoothingCounter = {};
        float glide = {};
        float glideFinal = {};
        float glideOut = {};
        float glideInc = {};
        float lfoPhase = {};
        float lfoFreq = {};
        float lfoSawA = {};
        float lfoTriangleA = {};
        float lfoPulseA = {};
        bool lfoPulseSign = {};
        float lfoShA = {};
        float lfoSh = {};
        float lfoConst = {};
        int64_t noiseMem = {};
        float noiseFilterFreq = {};
        float noiseFilterLPF = {};
        float lfoNoiseMix = {};
        float modulationWheel = {};
        float envelopeA_D_FAC = {};
        float envelopeA_R_FAC = {};
        float envelopeA_Rel = {};
        float envelopeA_Att = {};
        float envelopeA_Sus = {};
        float envelopeF_D_FAC = {};
        float envelopeF_R_FAC = {};
        float envelopeF_Rel = {};
        float envelopeF_Att = {};
        float envelopeF_Sus = {};
        float oscillatorB_PulseA = {};
        float oscillatorB_SawA = {};
        bool oscillatorB_TriA = {};
        float oscillatorB_FM_WM = {};
        float oscillatorB_PW = {};
        float oscillatorB_PW_Inc = {};
        float oscillatorB_PW_WM = {};
        float oscillatorB_LOF = {};
        float oscillatorB_Keyboard = {};
        float oscillatorB_Freq = {};
        float oscillatorB_Pitch = {};
        float oscillatorB_Fine = {};
        float polymodOscillatorB = {};
        float polymodEnvelopeF = {};
        float oscillatorA_SawA = {};
        float oscillatorA_FM_WM = {};
        float oscillatorA_FM_PM = {};
        float oscillatorA_PW = {};
        float oscillatorA_PW_Inc = {};
        float oscillatorA_PW_WM = {};
        float oscillatorA_PW_PM = {};
        bool oscillatorA_PulseActive = {};
        float oscillatorA_SawActive = {};
        float oscillatorA_Freq = {};
        bool oscillatorSyncActive = {};
        float mixerOscillatorA = {};
        float mixerOscillatorA_Inc = {};
        float mixerOscillatorB = {};
        float mixerOscillatorB_Inc = {};
        float mixerNoise = {};
        float mixerExternal = {};
        float filter_WM = {};
        float filter_PM = {};
        float filter_Env = {};
        float filter_EnvInc = {};
        bool filter_HPF = {};
        float filter_D = {};
        float filter_FMAX = {};
        float filter_Keyboard = {};
        float filter_KeyboardInc = {};
        float filter_Cutoff = {};
        float filter_Event = {};
        float filter_EventInc = {};
        float filter_Res = {};
        float filterN_D = {};
        float filterN_FMAX = {};
        float filter1HPF = {};
        int32_t smootherCount = {};
        float volumeSmooth = {};
        float volumeInc = {};
        bool delayActive = {};
        float delayDrySmooth = {};
        float delayDryInc = {};
        float delayWetSmooth = {};
        float delayWetInc = {};
        float delayFeedbackSmooth = {};
        float delayFeedbackInc = {};
        float delay_HPF_F = {};
        float delay_HPF_LPF = {};
        float delay_LPF_F = {};
        float delay_LPF_LPF = {};
        float delayTime_Mod_1 = {};
        float delayTime_Mod_2 = {};
        float delayTime_Mod_3 = {};
        float delayTime_Mod_4 = {};
        float delayTime_Inc_1 = {};
        float delayTime_Inc_2 = {};
        float delayTime_Inc_3 = {};
        float delayTime_Inc_4 = {};
        int32_t delayBufferIn = {};
        float A440Freq = {};
        float A440Phase = {};
        float A440PulseSign = {};
        float A440FilterFreq = {};
        float A440FilterLPF = {};
        float filterEnvelopeFinal = {};
        float filterKeyboardFinal = {};
        float oscillatorA_PW_Final = {};
        float oscillatorB_PW_Final = {};
        float mixerOscillatorA_Final = {};
        float mixerOscillatorB_Final = {};
        float volumeFinal = {};
        float delayWetKnob = {};
        float delayWetFinal = {};
        float delayDryFinal = {};
        float delayFeedbackKnob = {};
        float delayFeedbackFinal = {};
        float delayInv = {};
        float delaySum = {};
        float delayTime = {};
        float delayTimeRatio = {};
        float delayTime_1 = {};
        float delayTime_2 = {};
        float delayTime_3 = {};
        float delayTime_4 = {};
        float delayRate = {};
        float delayRate_1 = {};
        float delayRate_2 = {};
        float delayRate_3 = {};
        float delayRate_4 = {};
        float delayDepthKnob = {};
        float delayDepth = {};
        float delayLFO_Pos_1 = {};
        float delayLFO_Pos_2 = {};
        float delayLFO_Pos_3 = {};
        float delayLFO_Pos_4 = {};
        float delaySpread = {};
        float delayMIDI = {};
        bool delaySync = {};
        float lfoRatio = {};
        float midiTempo = {};
        float pitchBend = {};
        float masterTune = {};
        float tune = {};
        float velocityAmp = {};
        float velocityFilter = {};
        float filterEnvelopeInv = {};
        float envelopeRelease = {};
        bool unisonActive = {};
        float unisonNote = {};
        bool repeatActive = {};
        bool droneActive = {};
        float unisonGate = {};
        float filter_K = {};
        float noiseScale = {};
    };

    struct _Engine_1_VoiceState
    {
        bool isActive = {};
        float gate = {};
        float noteNumber = {};
        float pitch = {};
        float unisonRnd = {};
        float oscillatorA_Rnd = {};
        float oscillatorA_Tune = {};
        float oscillatorB_Rnd = {};
        float oscillatorB_Tune = {};
        float envelopeA_Out = {};
        float envelopeA_Level = {};
        float envelopeA_Peak = {};
        float envelopeA_Inc = {};
        float envelopeA_SDif = {};
        float envelopeA_Fac = {};
        int32_t envelopeA_Stage = {};
        float envelopeF_Out = {};
        float envelopeF_Level = {};
        float envelopeF_Peak = {};
        float envelopeF_Inc = {};
        float envelopeF_SDif = {};
        float envelopeF_Fac = {};
        int32_t envelopeF_Stage = {};
        float oscillatorB_F = {};
        float oscillatorB_Phase = {};
        float oscillatorB_Saw_AA2 = {};
        float oscillatorB_Pulse_AA2 = {};
        float polymodEnvRnd = {};
        float oscillatorA_F = {};
        float oscillatorA_Phase = {};
        float oscillatorA_Saw_AA2 = {};
        float oscillatorA_Pulse_AA2 = {};
        float eqLast = {};
        float filter_Event = {};
        float filter_BPF = {};
        float filter_LPF = {};
        float filter_F_Inc = {};
        float filter_F_Smooth = {};
        float filter_RND = {};
        float filterN_BPF = {};
        float filterN_LPF = {};
        float saturator_Out = {};
        float filter1HP_LPF = {};
        float filter_S0 = {};
        float filter_S1 = {};
        float filter_S2 = {};
        float filter_S3 = {};
        float filter_X = {};
        float filter_X_1 = {};
        float filter_X_2 = {};
        float filter_X_3 = {};
        float filter_X_4 = {};
        float filter_F0_4 = {};
        float filter_F0_1 = {};
        float filter_F0_2 = {};
        float filter_F0_3 = {};
        float filter_Mix = {};
        float oscillatorB_PW_OLD = {};
        int32_t oscillatorB_PulseLevel = {};
        int32_t oscillatorB_BUFWRITE = {};
        Array<float, 8> oscillatorB_BUF;
    };

    struct _Engine_1_State
    {
        float tau = {};
        float tauFilter = {};
        float piOverSampleRate = {};
        float noiseScale = {};
        _Engine_1_MonoSignals state;
        Array<_Engine_1_VoiceState, 32> voices;
        Array<float, 131072> delayBuffer;
        bool testToneActive = {};
        bool sustainActive = {};
        int32_t filterVersion = {};
        int32_t lastUnison = {};
        int32_t youngestOffVoice = {};
        int32_t oldestVoice = {};
        int32_t activeVoices = {};
        Array<int32_t, 32> collVoiceNext;
        Array<int32_t, 32> collVoicePrev;
        Array<int32_t, 32> collVoiceNote;
        Array<bool, 32> collVoiceSustain;
        Array<bool, 32> collVoiceHold;
        Array<float, 2401> exponentLUT;
        Array<float, 2400> exponentLUTSlope;
        int32_t _resumeIndex = {};
    };

    struct std_midi_MPEConverter_1_State
    {
    };

    struct _Pro54_State
    {
        int32_t _sessionID = {};
        double _frequency = {};
        _Engine_1_State engine;
        std_midi_MPEConverter_1_State _implicit_std__midi__MPEConverter;
    };

    struct Pro54_State
    {
        int32_t _currentFrame = {};
        _Pro54_State _state;
    };

    struct std_notes_NoteOn
    {
        int32_t channel = {};
        float pitch = {};
        float velocity = {};
    };

    struct std_notes_NoteOff
    {
        int32_t channel = {};
        float pitch = {};
        float velocity = {};
    };

    struct std_notes_PitchBend
    {
        int32_t channel = {};
        float bendSemitones = {};
    };

    struct std_notes_Control
    {
        int32_t channel = {};
        int32_t control = {};
        float value = {};
    };

    struct std_midi_Message
    {
        int32_t message = {};
    };

    struct std_notes_Pressure
    {
        int32_t channel = {};
        float pressure = {};
    };

    struct std_notes_Slide
    {
        int32_t channel = {};
        float slide = {};
    };

    struct Pro54_IO
    {
        Array<float, 512> externalIn;
        Array<Vector<float, 2>, 512> out;
    };

    struct _Pro54_IO
    {
        float externalIn = {};
        Vector<float, 2> out;
    };

    struct _Engine_1_IO
    {
        Vector<float, 2> out;
        float externalIn = {};
    };

    struct std_midi_MPEConverter_1_IO
    {
    };

    using _Engine_1_T = float;
    using _Engine_1_T_0 = float;
    using _Engine_1_T_1 = float;
    using std_intrinsics_T = float;
    using _Engine_1_T_2 = float;
    using _Engine_1_T_3 = float;
    using std_intrinsics_T_0 = float;
    using std_intrinsics_T_1 = float;
    using std_intrinsics_T_2 = double;
    using std_intrinsics_T_3 = float;
    using std_intrinsics_T_4 = float;
    using std_intrinsics_T_5 = float;
    using std_intrinsics_T_6 = float;
    using _Engine_1_T_4 = float;
    using std_intrinsics_T_7 = float;
    using std_intrinsics_T_8 = float;
    using std_intrinsics_T_9 = float;
    using std_intrinsics_T_10 = float;

    //==============================================================================
    double getMaxFrequency() const
    {
        return 192000.0;
    }

    void initialise (int32_t sessionID, double frequency)
    {
        assert (frequency <= getMaxFrequency());
        initSessionID = sessionID;
        initFrequency = frequency;
        reset();
    }

    void reset()
    {
        std::memset (&state, 0, sizeof (state));
        int32_t processorID = 0;
        _initialise (state, processorID, initSessionID, initFrequency);
    }

    void advance (int32_t frames)
    {
        io.out.clear (static_cast<SizeType> (frames));
        _advance (state, io, frames);
    }

    void copyOutputValue (EndpointHandle endpointHandle, void* dest)
    {
        (void) endpointHandle; (void) dest;

        assert (false); 
    }

    void copyParameterValue(EndpointHandle endpointHandle, void* dest) const
    {
      auto handle = static_cast<EndpointHandles> (endpointHandle);
      switch (handle)
      {
      case EndpointHandles::PolyModFilterEnv:
        memcpy (dest, std::addressof (state._state.engine.state.polymodEnvelopeF), sizeof (state._state.engine.state.polymodEnvelopeF));
        return;
      case EndpointHandles::PolyModOscB:
        memcpy (dest, std::addressof (state._state.engine.state.polymodOscillatorB), sizeof (state._state.engine.state.polymodOscillatorB));
        return;
      case EndpointHandles::PolyModFreqA:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorA_FM_PM), sizeof (state._state.engine.state.oscillatorA_FM_PM)); 
        return;
      case EndpointHandles::PolyModPWA:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorA_PW_PM), sizeof (state._state.engine.state.oscillatorA_PW_PM));
        return;
      case EndpointHandles::PolyModFilt:
        memcpy (dest, std::addressof (state._state.engine.state.filter_PM), sizeof (state._state.engine.state.filter_PM));
        return;
      case EndpointHandles::OscAFreq:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorA_Freq), sizeof (state._state.engine.state.oscillatorA_Freq));
        return;
      case EndpointHandles::OscASaw:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorA_SawActive), sizeof (state._state.engine.state.oscillatorA_SawActive));
        return;
      case EndpointHandles::OscAPulse:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorA_PulseActive), sizeof (state._state.engine.state.oscillatorA_PulseActive));
        return;
      case EndpointHandles::OscAPW:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorA_PW), sizeof (state._state.engine.state.oscillatorA_PW));
        return;
      case EndpointHandles::OscASync:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorSyncActive), sizeof (state._state.engine.state.oscillatorSyncActive));
        return;
      case EndpointHandles::MixerOscALevel:
        memcpy (dest, std::addressof (state._state.engine.state.mixerOscillatorA), sizeof (state._state.engine.state.mixerOscillatorA));
        return;
      case EndpointHandles::MixerOscBLevel:
        memcpy (dest, std::addressof (state._state.engine.state.mixerOscillatorB), sizeof (state._state.engine.state.mixerOscillatorB));
        return;
      case EndpointHandles::MixerNoiseLevel:
        memcpy (dest, std::addressof (state._state.engine.state.mixerNoise), sizeof (state._state.engine.state.mixerNoise));
        return;
      case EndpointHandles::ExternalInputLevel:
        memcpy (dest, std::addressof (state._state.engine.state.mixerExternal), sizeof (state._state.engine.state.mixerExternal));
        return;
      case EndpointHandles::FilterCutoff:
        //memcpy (dest, std::addressof (state._state.engine.state.filter_Cutoff), sizeof (state._state.engine.state.filter_Cutoff));
        *(static_cast<float*>(dest)) = normalizeGetFilterCutoff(state._state.engine.state.filter_Cutoff);
        return;
      case EndpointHandles::FilterResonance:
        memcpy (dest, std::addressof (state._state.engine.state.filter_Res), sizeof (state._state.engine.state.filter_Res));
        return;
      case EndpointHandles::FilterEnvAmt:
        memcpy (dest, std::addressof (state._state.engine.state.filter_Env), sizeof (state._state.engine.state.filter_Env));
        return;
      case EndpointHandles::FilterKeyboardTracking:
        memcpy (dest, std::addressof (state._state.engine.state.filter_Keyboard), sizeof (state._state.engine.state.filter_Keyboard));
        return;
      case EndpointHandles::FilterAttack:
        memcpy (dest, std::addressof (state._state.engine.state.envelopeF_Att), sizeof (state._state.engine.state.envelopeF_Att));
        return;
      case EndpointHandles::FilterDecay:
        memcpy (dest, std::addressof (state._state.engine.state.envelopeF_D_FAC), sizeof (state._state.engine.state.envelopeF_D_FAC));
        return;
      case EndpointHandles::FilterSustain:
        memcpy (dest, std::addressof (state._state.engine.state.envelopeF_Sus), sizeof (state._state.engine.state.envelopeF_Sus));
        return;
      case EndpointHandles::FilterRelease:
        memcpy (dest, std::addressof (state._state.engine.state.envelopeF_Rel), sizeof (state._state.engine.state.envelopeF_Rel));
        return;
      case EndpointHandles::DelayTime:
        memcpy (dest, std::addressof (state._state.engine.state.delayTime), sizeof (state._state.engine.state.delayTime)); 
        return;
      case EndpointHandles::DelaySpread:
        memcpy (dest, std::addressof (state._state.engine.state.delaySpread), sizeof (state._state.engine.state.delaySpread));
        return;
      case EndpointHandles::DelayDepth:
        memcpy (dest, std::addressof (state._state.engine.state.delayDepth), sizeof (state._state.engine.state.delayDepth));
        return;
      case EndpointHandles::DelayRate:
        memcpy (dest, std::addressof (state._state.engine.state.delayRate), sizeof (state._state.engine.state.delayRate));
        return;
      case EndpointHandles::DelayFeedback:
        memcpy (dest, std::addressof (state._state.engine.state.delayFeedbackKnob), sizeof (state._state.engine.state.delayFeedbackKnob));
        return;
      case EndpointHandles::DelayHiCut:
        memcpy (dest, std::addressof (state._state.engine.state.delay_HPF_F), sizeof (state._state.engine.state.delay_HPF_F));
        return;
      case EndpointHandles::DelayLoCut:
        memcpy (dest, std::addressof (state._state.engine.state.delay_LPF_F), sizeof (state._state.engine.state.delay_LPF_F));
        return;
      case EndpointHandles::DelayINV:
        memcpy (dest, std::addressof (state._state.engine.state.delayInv), sizeof (state._state.engine.state.delayInv));
        return;
      case EndpointHandles::DelayON:
        memcpy (dest, std::addressof (state._state.engine.state.delayActive), sizeof (state._state.engine.state.delayActive));
        return;
      case EndpointHandles::DelayWet:
        memcpy (dest, std::addressof (state._state.engine.state.delayWetKnob), sizeof (state._state.engine.state.delayWetKnob));
        return;
      case EndpointHandles::DelaySync:
        memcpy (dest, std::addressof (state._state.engine.state.delaySync), sizeof (state._state.engine.state.delaySync));
        return;
      case EndpointHandles::DelayMidi:
        memcpy (dest, std::addressof (state._state.engine.state.delayMIDI), sizeof (state._state.engine.state.delayMIDI));
        return;
      case EndpointHandles::LfoMidiSync:
        memcpy (dest, std::addressof (state._state.engine.state.lfoRatio), sizeof (state._state.engine.state.lfoRatio));
        return;
      case EndpointHandles::LfoFrequency:
        memcpy (dest, std::addressof (state._state.engine.state.lfoFreq), sizeof (state._state.engine.state.lfoFreq));
        return;
      case EndpointHandles::LfoShapeSaw:
        memcpy (dest, std::addressof (state._state.engine.state.lfoSawA), sizeof (state._state.engine.state.lfoSawA));
        return;
      case EndpointHandles::LfoShapeTri:
        memcpy (dest, std::addressof (state._state.engine.state.lfoTriangleA), sizeof (state._state.engine.state.lfoTriangleA));
        return;
      case EndpointHandles::LfoShapePulse:
        memcpy (dest, std::addressof (state._state.engine.state.lfoPulseA), sizeof (state._state.engine.state.lfoPulseA));
        return;
      case EndpointHandles::OscBFreq:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorB_Freq), sizeof (state._state.engine.state.oscillatorB_Freq));
        return;
      case EndpointHandles::OscBFreqFine:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorB_Fine), sizeof (state._state.engine.state.oscillatorB_Fine));
        return;
      case EndpointHandles::OscBShapeSaw:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorB_SawA), sizeof (state._state.engine.state.oscillatorB_SawA));
        return;
      case EndpointHandles::OscBShapeTri:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorB_TriA), sizeof (state._state.engine.state.oscillatorB_TriA));
        return;
      case EndpointHandles::OscBShapePulse:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorB_PulseA), sizeof (state._state.engine.state.oscillatorB_PulseA));
        return;
      case EndpointHandles::OscBPWAmount:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorB_PW), sizeof (state._state.engine.state.oscillatorB_PW));
        return;
      case EndpointHandles::OscBSubOsc:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorB_LOF), sizeof (state._state.engine.state.oscillatorB_LOF));
        return;
      case EndpointHandles::OscBKKeyboardTracking:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorB_Keyboard), sizeof (state._state.engine.state.oscillatorB_Keyboard));
        return;
      case EndpointHandles::WheelModulationLfoNoise:
        memcpy (dest, std::addressof (state._state.engine.state.lfoNoiseMix), sizeof (state._state.engine.state.lfoNoiseMix));
        return;
      case EndpointHandles::WheelModulationFreqOscA:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorA_FM_WM), sizeof (state._state.engine.state.oscillatorA_FM_WM));
        return;
      case EndpointHandles::WheelModulationFreqOscB:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorB_FM_WM), sizeof (state._state.engine.state.oscillatorB_FM_WM));
        return;
      case EndpointHandles::WheelModulationPWA:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorA_PW_WM), sizeof (state._state.engine.state.oscillatorA_PW_WM));
        return;
      case EndpointHandles::WheelModulationPWB:
        memcpy (dest, std::addressof (state._state.engine.state.oscillatorB_PW_WM), sizeof (state._state.engine.state.oscillatorB_PW_WM));
        return;
      case EndpointHandles::WheelModulationFilter:
        memcpy (dest, std::addressof (state._state.engine.state.filter_WM), sizeof (state._state.engine.state.filter_WM));
        return;
      case EndpointHandles::Glide:
        memcpy (dest, std::addressof (state._state.engine.state.glide), sizeof (state._state.engine.state.glide));
        return;
      case EndpointHandles::Unison:
        memcpy (dest, std::addressof (state._state.engine.state.unisonActive), sizeof (state._state.engine.state.unisonActive));
        return;
      case EndpointHandles::AmplifierAttack:
        memcpy (dest, std::addressof (state._state.engine.state.envelopeA_Att), sizeof (state._state.engine.state.envelopeA_Att));
        return;
      case EndpointHandles::AmplifierDecay:
        memcpy (dest, std::addressof (state._state.engine.state.envelopeA_D_FAC), sizeof (state._state.engine.state.envelopeA_D_FAC));
        return;
      case EndpointHandles::AmplifierSustain:
        memcpy (dest, std::addressof (state._state.engine.state.envelopeA_Sus), sizeof (state._state.engine.state.envelopeA_Sus));
        return;
      case EndpointHandles::AmplifierRelease:
        memcpy (dest, std::addressof (state._state.engine.state.envelopeA_Rel), sizeof (state._state.engine.state.envelopeA_Rel));
        return;
      case EndpointHandles::Release:
        memcpy (dest, std::addressof (state._state.engine.state.envelopeRelease), sizeof (state._state.engine.state.envelopeRelease));
        return;
      case EndpointHandles::Velocity:
        memcpy (dest, std::addressof (state._state.engine.state.velocityAmp), sizeof (state._state.engine.state.velocityAmp));
        return;
      case EndpointHandles::Repeat:
        memcpy (dest, std::addressof (state._state.engine.state.repeatActive), sizeof (state._state.engine.state.repeatActive));
        return;
      case EndpointHandles::Drone:
        memcpy (dest, std::addressof (state._state.engine.state.droneActive), sizeof (state._state.engine.state.droneActive));
        return;
      case EndpointHandles::FilterHPF:
        memcpy (dest, std::addressof (state._state.engine.state.filter_HPF), sizeof (state._state.engine.state.filter_HPF));
        return;
      case EndpointHandles::FilterInvertEnv:
        memcpy (dest, std::addressof (state._state.engine.state.filterEnvelopeInv), sizeof (state._state.engine.state.filterEnvelopeInv));
        return;
      case EndpointHandles::Analog:
        memcpy (dest, std::addressof (state._state.engine.state.noiseScale), sizeof (state._state.engine.state.noiseScale));
        return;
      case EndpointHandles::MasterTune:
        memcpy (dest, std::addressof (state._state.engine.state.masterTune), sizeof (state._state.engine.state.masterTune));
        return;
      case EndpointHandles::Volume:
        memcpy (dest, std::addressof (state._state.engine.state.volumeFinal), sizeof (state._state.engine.state.volumeFinal));
        return;
      case EndpointHandles::ModWheel:
        memcpy (dest, std::addressof (state._state.engine.state.modulationWheel), sizeof (state._state.engine.state.modulationWheel));
        return;
      case EndpointHandles::PitchBend:
        memcpy (dest, std::addressof (state._state.engine.state.pitchBend), sizeof (state._state.engine.state.pitchBend));
        return;
      case EndpointHandles::FilterVersion:
        memcpy (dest, std::addressof (state._state.engine.filterVersion), sizeof (state._state.engine.filterVersion));
        return;
      case EndpointHandles::ActiveVoices:
        memcpy (dest, std::addressof (state._state.engine.activeVoices), sizeof (state._state.engine.activeVoices));
        return;
      case EndpointHandles::TestTone:
        memcpy (dest, std::addressof (state._state.engine.testToneActive), sizeof (state._state.engine.testToneActive));
        return;
    
        
      case EndpointHandles::eventIn: 
      case EndpointHandles::externalIn:
      case EndpointHandles::midiIn:
      case EndpointHandles::out:
        return;

        assert (false);
      }
    }

    void copyOutputFrames (EndpointHandle endpointHandle, void* dest, uint32_t numFramesToCopy)
    {
        if (endpointHandle == 77) { std::memcpy (dest, std::addressof (io.out), 8 * numFramesToCopy); std::memset (std::addressof (io.out), 0, 8 * numFramesToCopy); return; }
        assert (false);
    }

    uint32_t getNumOutputEvents (EndpointHandle endpointHandle)
    {
        (void) endpointHandle;

        assert (false); return {};
    }

    void resetOutputEventCount (EndpointHandle endpointHandle)
    {
        (void) endpointHandle;
    }

    uint32_t getOutputEventType (EndpointHandle endpointHandle, uint32_t index)
    {
        (void) endpointHandle; (void) index;

        assert (false); return {};
    }

    static uint32_t getOutputEventDataSize (EndpointHandle endpointHandle, uint32_t typeIndex)
    {
        (void) endpointHandle; (void) typeIndex;

        assert (false); return 0;
    }

    uint32_t readOutputEvent (EndpointHandle endpointHandle, uint32_t index, unsigned char* dest)
    {

        (void) endpointHandle; (void) index; (void) dest;

        assert (false);
        return {};
    }

    void addEvent_eventIn (const std_notes_NoteOn& event)
    {
        _sendEvent_eventIn_1 (state, event);
    }

    void addEvent_eventIn (const std_notes_NoteOff& event)
    {
        _sendEvent_eventIn_2 (state, event);
    }

    void addEvent_eventIn (const std_notes_PitchBend& event)
    {
        _sendEvent_eventIn_3 (state, event);
    }

    void addEvent_eventIn (const std_notes_Control& event)
    {
        _sendEvent_eventIn_4 (state, event);
    }

    void addEvent_PolyModFilterEnv (float event)
    {
        _sendEvent_PolyModFilterEnv (state, event);
    }

    void addEvent_PolyModOscB (float event)
    {
        _sendEvent_PolyModOscB (state, event);
    }

    void addEvent_PolyModFreqA (float event)
    {
        _sendEvent_PolyModFreqA (state, event);
    }

    void addEvent_PolyModPWA (float event)
    {
        _sendEvent_PolyModPWA (state, event);
    }

    void addEvent_PolyModFilt (float event)
    {
        _sendEvent_PolyModFilt (state, event);
    }

    void addEvent_OscAFreq (float event)
    {
        _sendEvent_OscAFreq (state, event);
    }

    void addEvent_OscASaw (float event)
    {
        _sendEvent_OscASaw (state, event);
    }

    void addEvent_OscAPulse (float event)
    {
        _sendEvent_OscAPulse (state, event);
    }

    void addEvent_OscAPW (float event)
    {
        _sendEvent_OscAPW (state, event);
    }

    void addEvent_OscASync (float event)
    {
        _sendEvent_OscASync (state, event);
    }

    void addEvent_MixerOscALevel (float event)
    {
        _sendEvent_MixerOscALevel (state, event);
    }

    void addEvent_MixerOscBLevel (float event)
    {
        _sendEvent_MixerOscBLevel (state, event);
    }

    void addEvent_MixerNoiseLevel (float event)
    {
        _sendEvent_MixerNoiseLevel (state, event);
    }

    void addEvent_ExternalInputLevel (float event)
    {
        _sendEvent_ExternalInputLevel (state, event);
    }

    void addEvent_FilterCutoff (float event)
    {
        _sendEvent_FilterCutoff (state, event);
    }

    void addEvent_FilterResonance (float event)
    {
        _sendEvent_FilterResonance (state, event);
    }

    void addEvent_FilterEnvAmt (float event)
    {
        _sendEvent_FilterEnvAmt (state, event);
    }

    void addEvent_FilterKeyboardTracking (float event)
    {
        _sendEvent_FilterKeyboardTracking (state, event);
    }

    void addEvent_FilterAttack (float event)
    {
        _sendEvent_FilterAttack (state, event);
    }

    void addEvent_FilterDecay (float event)
    {
        _sendEvent_FilterDecay (state, event);
    }

    void addEvent_FilterSustain (float event)
    {
        _sendEvent_FilterSustain (state, event);
    }

    void addEvent_FilterRelease (float event)
    {
        _sendEvent_FilterRelease (state, event);
    }

    void addEvent_DelayTime (float event)
    {
        _sendEvent_DelayTime (state, event);
    }

    void addEvent_DelaySpread (float event)
    {
        _sendEvent_DelaySpread (state, event);
    }

    void addEvent_DelayDepth (float event)
    {
        _sendEvent_DelayDepth (state, event);
    }

    void addEvent_DelayRate (float event)
    {
        _sendEvent_DelayRate (state, event);
    }

    void addEvent_DelayFeedback (float event)
    {
        _sendEvent_DelayFeedback (state, event);
    }

    void addEvent_DelayHiCut (float event)
    {
        _sendEvent_DelayHiCut (state, event);
    }

    void addEvent_DelayLoCut (float event)
    {
        _sendEvent_DelayLoCut (state, event);
    }

    void addEvent_DelayINV (float event)
    {
        _sendEvent_DelayINV (state, event);
    }

    void addEvent_DelayON (float event)
    {
        _sendEvent_DelayON (state, event);
    }

    void addEvent_DelayWet (float event)
    {
        _sendEvent_DelayWet (state, event);
    }

    void addEvent_DelaySync (float event)
    {
        _sendEvent_DelaySync (state, event);
    }

    void addEvent_DelayMidi (float event)
    {
        _sendEvent_DelayMidi (state, event);
    }

    void addEvent_LfoMidiSync (float event)
    {
        _sendEvent_LfoMidiSync (state, event);
    }

    void addEvent_LfoFrequency (float event)
    {
        _sendEvent_LfoFrequency (state, event);
    }

    void addEvent_LfoShapeSaw (float event)
    {
        _sendEvent_LfoShapeSaw (state, event);
    }

    void addEvent_LfoShapeTri (float event)
    {
        _sendEvent_LfoShapeTri (state, event);
    }

    void addEvent_LfoShapePulse (float event)
    {
        _sendEvent_LfoShapePulse (state, event);
    }

    void addEvent_OscBFreq (float event)
    {
        _sendEvent_OscBFreq (state, event);
    }

    void addEvent_OscBFreqFine (float event)
    {
        _sendEvent_OscBFreqFine (state, event);
    }

    void addEvent_OscBShapeSaw (float event)
    {
        _sendEvent_OscBShapeSaw (state, event);
    }

    void addEvent_OscBShapeTri (float event)
    {
        _sendEvent_OscBShapeTri (state, event);
    }

    void addEvent_OscBShapePulse (float event)
    {
        _sendEvent_OscBShapePulse (state, event);
    }

    void addEvent_OscBPWAmount (float event)
    {
        _sendEvent_OscBPWAmount (state, event);
    }

    void addEvent_OscBSubOsc (float event)
    {
        _sendEvent_OscBSubOsc (state, event);
    }

    void addEvent_OscBKKeyboardTracking (float event)
    {
        _sendEvent_OscBKKeyboardTracking (state, event);
    }

    void addEvent_WheelModulationLfoNoise (float event)
    {
        _sendEvent_WheelModulationLfoNoise (state, event);
    }

    void addEvent_WheelModulationFreqOscA (float event)
    {
        _sendEvent_WheelModulationFreqOscA (state, event);
    }

    void addEvent_WheelModulationFreqOscB (float event)
    {
        _sendEvent_WheelModulationFreqOscB (state, event);
    }

    void addEvent_WheelModulationPWA (float event)
    {
        _sendEvent_WheelModulationPWA (state, event);
    }

    void addEvent_WheelModulationPWB (float event)
    {
        _sendEvent_WheelModulationPWB (state, event);
    }

    void addEvent_WheelModulationFilter (float event)
    {
        _sendEvent_WheelModulationFilter (state, event);
    }

    void addEvent_Glide (float event)
    {
        _sendEvent_Glide (state, event);
    }

    void addEvent_Unison (float event)
    {
        _sendEvent_Unison (state, event);
    }

    void addEvent_AmplifierAttack (float event)
    {
        _sendEvent_AmplifierAttack (state, event);
    }

    void addEvent_AmplifierDecay (float event)
    {
        _sendEvent_AmplifierDecay (state, event);
    }

    void addEvent_AmplifierSustain (float event)
    {
        _sendEvent_AmplifierSustain (state, event);
    }

    void addEvent_AmplifierRelease (float event)
    {
        _sendEvent_AmplifierRelease (state, event);
    }

    void addEvent_Release (float event)
    {
        _sendEvent_Release (state, event);
    }

    void addEvent_Velocity (float event)
    {
        _sendEvent_Velocity (state, event);
    }

    void addEvent_Repeat (float event)
    {
        _sendEvent_Repeat (state, event);
    }

    void addEvent_Drone (float event)
    {
        _sendEvent_Drone (state, event);
    }

    void addEvent_FilterHPF (float event)
    {
        _sendEvent_FilterHPF (state, event);
    }

    void addEvent_FilterInvertEnv (float event)
    {
        _sendEvent_FilterInvertEnv (state, event);
    }

    void addEvent_Analog (float event)
    {
        _sendEvent_Analog (state, event);
    }

    void addEvent_MasterTune (float event)
    {
        _sendEvent_MasterTune (state, event);
    }

    void addEvent_Volume (float event)
    {
        _sendEvent_Volume (state, event);
    }

    void addEvent_ModWheel (float event)
    {
        _sendEvent_ModWheel (state, event);
    }

    void addEvent_PitchBend (float event)
    {
        _sendEvent_PitchBend (state, event);
    }

    void addEvent_FilterVersion (float event)
    {
        _sendEvent_FilterVersion (state, event);
    }

    void addEvent_ActiveVoices (float event)
    {
        _sendEvent_ActiveVoices (state, event);
    }

    void addEvent_TestTone (float event)
    {
        _sendEvent_TestTone (state, event);
    }

    void addEvent_midiIn (const std_midi_Message& event)
    {
        _sendEvent_midiIn (state, event);
    }

    void addEvent (EndpointHandle endpointHandle, uint32_t typeIndex, const unsigned char* eventData)
    {
        (void) endpointHandle; (void) typeIndex; (void) eventData;

        if (endpointHandle == 1 && typeIndex == 0)
        {
 std_notes_NoteOn value;
 memcpy (&value.channel, eventData, 4);
 eventData += 4;
 memcpy (&value.pitch, eventData, 4);
 eventData += 4;
 memcpy (&value.velocity, eventData, 4);
 eventData += 4;
 return addEvent_eventIn (value);
        }

        if (endpointHandle == 1 && typeIndex == 1)
        {
 std_notes_NoteOff value;
 memcpy (&value.channel, eventData, 4);
 eventData += 4;
 memcpy (&value.pitch, eventData, 4);
 eventData += 4;
 memcpy (&value.velocity, eventData, 4);
 eventData += 4;
 return addEvent_eventIn (value);
        }

        if (endpointHandle == 1 && typeIndex == 2)
        {
 std_notes_PitchBend value;
 memcpy (&value.channel, eventData, 4);
 eventData += 4;
 memcpy (&value.bendSemitones, eventData, 4);
 eventData += 4;
 return addEvent_eventIn (value);
        }

        if (endpointHandle == 1 && typeIndex == 3)
        {
 std_notes_Control value;
 memcpy (&value.channel, eventData, 4);
 eventData += 4;
 memcpy (&value.control, eventData, 4);
 eventData += 4;
 memcpy (&value.value, eventData, 4);
 eventData += 4;
 return addEvent_eventIn (value);
        }

        if (endpointHandle == 3)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_PolyModFilterEnv (value);
        }

        if (endpointHandle == 4)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_PolyModOscB (value);
        }

        if (endpointHandle == 5)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_PolyModFreqA (value);
        }

        if (endpointHandle == 6)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_PolyModPWA (value);
        }

        if (endpointHandle == 7)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_PolyModFilt (value);
        }

        if (endpointHandle == 8)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_OscAFreq (value);
        }

        if (endpointHandle == 9)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_OscASaw (value);
        }

        if (endpointHandle == 10)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_OscAPulse (value);
        }

        if (endpointHandle == 11)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_OscAPW (value);
        }

        if (endpointHandle == 12)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_OscASync (value);
        }

        if (endpointHandle == 13)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_MixerOscALevel (value);
        }

        if (endpointHandle == 14)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_MixerOscBLevel (value);
        }

        if (endpointHandle == 15)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_MixerNoiseLevel (value);
        }

        if (endpointHandle == 16)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_ExternalInputLevel (value);
        }

        if (endpointHandle == 17)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_FilterCutoff (value);
        }

        if (endpointHandle == 18)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_FilterResonance (value);
        }

        if (endpointHandle == 19)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_FilterEnvAmt (value);
        }

        if (endpointHandle == 20)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_FilterKeyboardTracking (value);
        }

        if (endpointHandle == 21)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_FilterAttack (value);
        }

        if (endpointHandle == 22)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_FilterDecay (value);
        }

        if (endpointHandle == 23)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_FilterSustain (value);
        }

        if (endpointHandle == 24)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_FilterRelease (value);
        }

        if (endpointHandle == 25)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_DelayTime (value);
        }

        if (endpointHandle == 26)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_DelaySpread (value);
        }

        if (endpointHandle == 27)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_DelayDepth (value);
        }

        if (endpointHandle == 28)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_DelayRate (value);
        }

        if (endpointHandle == 29)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_DelayFeedback (value);
        }

        if (endpointHandle == 30)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_DelayHiCut (value);
        }

        if (endpointHandle == 31)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_DelayLoCut (value);
        }

        if (endpointHandle == 32)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_DelayINV (value);
        }

        if (endpointHandle == 33)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_DelayON (value);
        }

        if (endpointHandle == 34)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_DelayWet (value);
        }

        if (endpointHandle == 35)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_DelaySync (value);
        }

        if (endpointHandle == 36)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_DelayMidi (value);
        }

        if (endpointHandle == 37)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_LfoMidiSync (value);
        }

        if (endpointHandle == 38)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_LfoFrequency (value);
        }

        if (endpointHandle == 39)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_LfoShapeSaw (value);
        }

        if (endpointHandle == 40)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_LfoShapeTri (value);
        }

        if (endpointHandle == 41)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_LfoShapePulse (value);
        }

        if (endpointHandle == 42)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_OscBFreq (value);
        }

        if (endpointHandle == 43)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_OscBFreqFine (value);
        }

        if (endpointHandle == 44)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_OscBShapeSaw (value);
        }

        if (endpointHandle == 45)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_OscBShapeTri (value);
        }

        if (endpointHandle == 46)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_OscBShapePulse (value);
        }

        if (endpointHandle == 47)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_OscBPWAmount (value);
        }

        if (endpointHandle == 48)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_OscBSubOsc (value);
        }

        if (endpointHandle == 49)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_OscBKKeyboardTracking (value);
        }

        if (endpointHandle == 50)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_WheelModulationLfoNoise (value);
        }

        if (endpointHandle == 51)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_WheelModulationFreqOscA (value);
        }

        if (endpointHandle == 52)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_WheelModulationFreqOscB (value);
        }

        if (endpointHandle == 53)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_WheelModulationPWA (value);
        }

        if (endpointHandle == 54)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_WheelModulationPWB (value);
        }

        if (endpointHandle == 55)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_WheelModulationFilter (value);
        }

        if (endpointHandle == 56)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_Glide (value);
        }

        if (endpointHandle == 57)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_Unison (value);
        }

        if (endpointHandle == 58)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_AmplifierAttack (value);
        }

        if (endpointHandle == 59)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_AmplifierDecay (value);
        }

        if (endpointHandle == 60)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_AmplifierSustain (value);
        }

        if (endpointHandle == 61)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_AmplifierRelease (value);
        }

        if (endpointHandle == 62)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_Release (value);
        }

        if (endpointHandle == 63)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_Velocity (value);
        }

        if (endpointHandle == 64)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_Repeat (value);
        }

        if (endpointHandle == 65)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_Drone (value);
        }

        if (endpointHandle == 66)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_FilterHPF (value);
        }

        if (endpointHandle == 67)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_FilterInvertEnv (value);
        }

        if (endpointHandle == 68)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_Analog (value);
        }

        if (endpointHandle == 69)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_MasterTune (value);
        }

        if (endpointHandle == 70)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_Volume (value);
        }

        if (endpointHandle == 71)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_ModWheel (value);
        }

        if (endpointHandle == 72)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_PitchBend (value);
        }

        if (endpointHandle == 73)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_FilterVersion (value);
        }

        if (endpointHandle == 74)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_ActiveVoices (value);
        }

        if (endpointHandle == 75)
        {
 float value;
 memcpy (&value, eventData, 4);
 eventData += 4;
 return addEvent_TestTone (value);
        }

        if (endpointHandle == 76)
        {
 std_midi_Message value;
 memcpy (&value.message, eventData, 4);
 eventData += 4;
 return addEvent_midiIn (value);
        }
    }

    void setValue (EndpointHandle endpointHandle, const void* value, int32_t frames)
    {
        (void) endpointHandle; (void) value; (void) frames;
    }

    void setInputFrames_externalIn (const void* data, uint32_t numFrames, uint32_t numTrailingFramesToClear)
    {
        memcpy (io.externalIn.elements, data, numFrames * 4);
        if (numTrailingFramesToClear != 0) memset (io.externalIn.elements + numFrames, 0, numTrailingFramesToClear * 4);
    }

    void setInputFrames (EndpointHandle endpointHandle, const void* frameData, uint32_t numFrames, uint32_t numTrailingFramesToClear)
    {
        if (endpointHandle == 2) return setInputFrames_externalIn (frameData, numFrames, numTrailingFramesToClear);
    }

    //==============================================================================
    // Rendering state values
    int32_t initSessionID;
    double initFrequency;
    Pro54_State state = {};
    Pro54_IO io = {};

    //==============================================================================
    void _sendEvent_eventIn_1 (Pro54_State& _state, std_notes_NoteOn value) noexcept
    {
        _Pro54__eventIn (_state._state, value);
    }

    void _Pro54__eventIn (_Pro54_State& _state, std_notes_NoteOn value) noexcept
    {
        Engine__eventIn (_state.engine, value);
    }

    void Engine__eventIn (_Engine_1_State& _state, std_notes_NoteOn e) noexcept
    {
        auto _tempArg_0 = static_cast<int32_t> (e.pitch);
        Engine__noteOn (_state, _tempArg_0, static_cast<int32_t> (e.velocity * 128.0f), 0.0f);
    }

    void Engine__noteOn (_Engine_1_State& _state, int32_t note, int32_t vel, float detune) noexcept
    {
        int32_t  n;
        int32_t  v;

        n = Engine__allocateVoice (_state, _state.oldestVoice, note);
        if (n < int32_t {0})
        {
 return;
        }
        v = n & int32_t {31};
        _state.collVoiceNote[v & int32_t {31}] = note;
        if (Engine__triggerNoteOn (_state, v, vel, detune))
        {
 if (_state.state.unisonActive)
 {
     _state.lastUnison = note;
 }
        }
        _state.collVoiceSustain[v & int32_t {31}] = false;
        _state.collVoiceHold[v & int32_t {31}] = false;
    }

    int32_t Engine__allocateVoice (_Engine_1_State& _state, int32_t last, int32_t note) noexcept
    {
        int32_t  v;
        int32_t  s;
        int32_t  s_0;
        int32_t  s_1;
        int32_t  v_0;
        bool  foundOldest;

        {
 v = int32_t {0};
 for (;;)
 {
     if  (! (v < _state.activeVoices))
     {
         break;
     }
     if ((_state.collVoiceNote[v & int32_t {31}] == note) ? true : (_state.collVoiceNote[v & int32_t {31}] == (noteOffMarker - note)))
     {
         s = v;
         if (s == _state.oldestVoice)
         {
  _state.oldestVoice = _state.collVoiceNext[_state.oldestVoice & int32_t {31}];
  if (s == _state.youngestOffVoice)
  {
      _state.youngestOffVoice = int32_t {-1};
  }
         }
         else
         {
  if (s == _state.youngestOffVoice)
  {
      _state.youngestOffVoice = _state.collVoicePrev[_state.youngestOffVoice & int32_t {31}];
  }
         }
         Engine__insertBefore (_state, last & int32_t {31}, s & int32_t {31});
         return s;
     }
     {
         ++v;
     }
 }
        }
        if (_state.youngestOffVoice >= int32_t {0})
        {
 s_0 = _state.oldestVoice & int32_t {31};
 _state.oldestVoice = _state.collVoiceNext[_state.oldestVoice & int32_t {31}];
 if (s_0 == _state.youngestOffVoice)
 {
     _state.youngestOffVoice = int32_t {-1};
 }
 Engine__insertBefore (_state, last & int32_t {31}, s_0 & int32_t {31});
 return s_0;
        }
        s_1 = _state.collVoicePrev[last & int32_t {31}];
        v_0 = s_1;
        foundOldest = {};
        for (;;)
        {
 if  (! (! foundOldest))
 {
     break;
 }
 s_1 = v_0;
 v_0 = _state.collVoicePrev[v_0 & int32_t {31}];
 foundOldest = (v_0 == _state.collVoicePrev[_state.oldestVoice & int32_t {31}]);
        }
        if (s_1 == _state.oldestVoice)
        {
 _state.oldestVoice = _state.collVoiceNext[_state.oldestVoice & int32_t {31}];
        }
        Engine__insertBefore (_state, last & int32_t {31}, s_1 & int32_t {31});
        return s_1;
    }

    void Engine__insertBefore (_Engine_1_State& _state, int32_t dest, int32_t source) noexcept
    {
        if (source != dest)
        {
 Engine__insertAfter (_state, _state.collVoicePrev[dest] & int32_t {31}, source);
        }
    }

    void Engine__insertAfter (_Engine_1_State& _state, int32_t dest, int32_t source) noexcept
    {
        if (source == dest)
        {
 return;
        }
        _state.collVoiceNext[(_state.collVoicePrev[source] & int32_t {31}) & int32_t {31}] = _state.collVoiceNext[source];
        _state.collVoicePrev[(_state.collVoiceNext[source] & int32_t {31}) & int32_t {31}] = _state.collVoicePrev[source];
        _state.collVoiceNext[source] = _state.collVoiceNext[dest];
        _state.collVoicePrev[source] = dest;
        _state.collVoicePrev[(_state.collVoiceNext[dest] & int32_t {31}) & int32_t {31}] = source;
        _state.collVoiceNext[dest] = source;
    }

    bool Engine__triggerNoteOn (_Engine_1_State& _state, int32_t voice, int32_t vel, float Detune) noexcept
    {
        int32_t  notePitch;
        float  scaledPitch;
        int32_t  v;
        int32_t  numActiveVoices;
        int32_t  v_0;
        float  peakA;
        float  peakF;
        int32_t  v_1;
        float  peakA_0;
        float  peakF_0;
        int32_t  v_2;
        int32_t  numActiveVoices_0;
        int32_t  v_3;
        float  peakA_1;
        float  peakF_1;

        notePitch = _state.collVoiceNote[voice];
        _state.voices[voice].noteNumber = static_cast<float> (notePitch);
        scaledPitch = _state.voices[voice].noteNumber + Detune;
        if (_state.state.unisonActive)
        {
 _state.state.unisonNote = static_cast<float> (notePitch);
 _state.state.glideFinal = scaledPitch;
 if (_state.state.glideFinal == _state.state.glideOut)
 {
     _state.state.glideInc = 0.0f;
     {
         v = {};
         for (;;)
         {
  if (v >= int32_t {32})
  {
      break;
  }
  if (v == _state.activeVoices)
  {
      break;
  }
  _state.voices[v].pitch = (_state.state.glideFinal + _state.voices[v].unisonRnd);
  _state.voices[v].oscillatorA_F = Engine__pitchToFreq (_state, _state.voices[v].pitch + _state.voices[v].oscillatorA_Tune);
  _state.voices[v].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[v].pitch) + _state.voices[v].oscillatorB_Tune);
  {
      ++v;
  }
         }
     }
 }
 else
 {
     if (_state.state.glideFinal > _state.state.glideOut)
     {
         _state.state.glideInc = ((_state.state.glide * _state.tau) * 1.0f);
     }
     else
     {
         _state.state.glideInc = (((- _state.state.glide) * _state.tau) * 1.0f);
     }
 }
 _state.state.unisonGate = 1.0f;
 numActiveVoices = {};
 {
     v_0 = {};
     for (;;)
     {
         if (v_0 >= int32_t {32})
         {
  break;
         }
         if (v_0 == _state.activeVoices)
         {
  break;
         }
         if (static_cast<double> (_state.voices[v_0].gate) > 0.0)
         {
  ++numActiveVoices;
         }
         {
  ++v_0;
         }
     }
 }
 if (_state.state.repeatActive)
 {
     if ((_state.state.midiTempo == static_cast<float> (int32_t {0})) ? (numActiveVoices == int32_t {0}) : false)
     {
         _state.state.lfoPhase = 1.0f;
     }
 }
 else
 {
     if (numActiveVoices == int32_t {0})
     {
         peakA = 0.5f + (_state.state.velocityAmp * ((static_cast<float> (vel) * 0.0078125f) - 0.5f));
         peakF = 0.5f + (_state.state.velocityFilter * ((static_cast<float> (vel) * 0.0078125f) - 0.5f));
         {
  v_1 = {};
  for (;;)
  {
      if (v_1 >= int32_t {32})
      {
          break;
      }
      if (v_1 == _state.activeVoices)
      {
          break;
      }
      _state.voices[v_1].isActive = true;
      if (static_cast<double> (_state.voices[v_1].envelopeA_Out) < 0.0)
      {
          _state.voices[v_1].envelopeA_Out = 0.0f;
      }
      if (_state.voices[v_1].envelopeA_Out > peakA)
      {
          _state.voices[v_1].envelopeA_Peak = _state.voices[v_1].envelopeA_Out;
          _state.voices[v_1].envelopeA_Stage = int32_t {1};
          _state.voices[v_1].envelopeA_Fac = _state.state.envelopeA_D_FAC;
          _state.voices[v_1].envelopeA_Level = (((_state.voices[v_1].envelopeA_Peak - envelopeAOffset) * _state.state.envelopeA_Sus) + envelopeAOffset);
          _state.voices[v_1].envelopeA_SDif = (_state.voices[v_1].envelopeA_Peak - _state.voices[v_1].envelopeA_Level);
      }
      else
      {
          _state.voices[v_1].envelopeA_Inc = (peakA * _state.state.envelopeA_Att);
          _state.voices[v_1].envelopeA_Peak = peakA;
          _state.voices[v_1].envelopeA_Stage = int32_t {0};
      }
      if (_state.voices[v_1].envelopeF_Out > peakF)
      {
          _state.voices[v_1].envelopeF_Peak = _state.voices[v_1].envelopeF_Out;
          _state.voices[v_1].envelopeF_Stage = int32_t {1};
          _state.voices[v_1].envelopeF_Fac = _state.state.envelopeF_D_FAC;
          _state.voices[v_1].envelopeF_Level = (_state.voices[v_1].envelopeF_Peak * _state.state.envelopeF_Sus);
          _state.voices[v_1].envelopeF_SDif = (_state.voices[v_1].envelopeF_Out - _state.voices[v_1].envelopeF_Level);
      }
      else
      {
          _state.voices[v_1].envelopeF_Inc = (peakF * _state.state.envelopeF_Att);
          _state.voices[v_1].envelopeF_Peak = peakF;
          _state.voices[v_1].envelopeF_Stage = int32_t {0};
          _state.voices[v_1].envelopeF_SDif = 1.0f;
      }
      {
          ++v_1;
      }
  }
         }
     }
     else
     {
         peakA_0 = 0.5f + (_state.state.velocityAmp * ((static_cast<float> (vel) * 0.0078125f) - 0.5f));
         peakF_0 = 0.5f + (_state.state.velocityFilter * ((static_cast<float> (vel) * 0.0078125f) - 0.5f));
         {
  v_2 = {};
  for (;;)
  {
      if (v_2 >= int32_t {32})
      {
          break;
      }
      if (v_2 == _state.activeVoices)
      {
          break;
      }
      _state.voices[v_2].envelopeA_Peak = peakA_0;
      if ((_state.voices[v_2].envelopeA_Stage == int32_t {0}) ? (_state.voices[v_2].envelopeA_Out < peakA_0) : false)
      {
          _state.voices[v_2].envelopeA_Inc = (peakA_0 * _state.state.envelopeA_Att);
      }
      else
      {
          _state.voices[v_2].envelopeA_Stage = int32_t {1};
          _state.voices[v_2].envelopeA_Fac = _state.state.envelopeA_D_FAC;
          _state.voices[v_2].envelopeA_Level = (((_state.voices[v_2].envelopeA_Peak - envelopeAOffset) * _state.state.envelopeA_Sus) + envelopeAOffset);
          _state.voices[v_2].envelopeA_SDif = (_state.voices[v_2].envelopeA_Out - _state.voices[v_2].envelopeA_Level);
      }
      _state.voices[v_2].envelopeF_Peak = peakF_0;
      if ((_state.voices[v_2].envelopeF_Stage == int32_t {0}) ? (_state.voices[v_2].envelopeF_Out < peakF_0) : false)
      {
          _state.voices[v_2].envelopeF_Inc = (peakF_0 * _state.state.envelopeF_Att);
          _state.voices[v_2].envelopeF_SDif = 1.0f;
      }
      else
      {
          _state.voices[v_2].envelopeF_Stage = int32_t {1};
          _state.voices[v_2].envelopeF_Fac = _state.state.envelopeF_D_FAC;
          _state.voices[v_2].envelopeF_Level = (_state.voices[v_2].envelopeF_Peak * _state.state.envelopeF_Sus);
          _state.voices[v_2].envelopeF_SDif = (_state.voices[v_2].envelopeF_Out - _state.voices[v_2].envelopeF_Level);
      }
      {
          ++v_2;
      }
  }
         }
     }
 }
        }
        else
        {
 if (_state.state.repeatActive)
 {
     if (_state.state.midiTempo == static_cast<float> (int32_t {0}))
     {
         numActiveVoices_0 = {};
         {
  v_3 = {};
  for (;;)
  {
      if (v_3 >= int32_t {32})
      {
          break;
      }
      if (v_3 == _state.activeVoices)
      {
          break;
      }
      if (static_cast<double> (_state.voices[v_3].gate) > 0.0)
      {
          ++numActiveVoices_0;
      }
      {
          ++v_3;
      }
  }
         }
         if (numActiveVoices_0 == int32_t {0})
         {
  _state.state.lfoPhase = 1.0f;
         }
     }
 }
 else
 {
     peakA_1 = 0.5f + (_state.state.velocityAmp * ((static_cast<float> (vel) * 0.0078125f) - 0.5f));
     peakF_1 = 0.5f + (_state.state.velocityFilter * ((static_cast<float> (vel) * 0.0078125f) - 0.5f));
     _state.voices[voice].isActive = true;
     if (_state.voices[voice].envelopeA_Out > peakA_1)
     {
         _state.voices[voice].envelopeA_Peak = _state.voices[voice].envelopeA_Out;
         _state.voices[voice].envelopeA_Stage = int32_t {1};
         _state.voices[voice].envelopeA_Fac = _state.state.envelopeA_D_FAC;
         _state.voices[voice].envelopeA_Level = (((_state.voices[voice].envelopeA_Peak - envelopeAOffset) * _state.state.envelopeA_Sus) + envelopeAOffset);
         _state.voices[voice].envelopeA_SDif = (_state.voices[voice].envelopeA_Peak - _state.voices[voice].envelopeA_Level);
     }
     else
     {
         _state.voices[voice].envelopeA_Inc = (peakA_1 * _state.state.envelopeA_Att);
         _state.voices[voice].envelopeA_Peak = peakA_1;
         _state.voices[voice].envelopeA_Stage = int32_t {0};
     }
     if (_state.voices[voice].envelopeF_Out > peakF_1)
     {
         _state.voices[voice].envelopeF_Peak = _state.voices[voice].envelopeF_Out;
         _state.voices[voice].envelopeF_Stage = int32_t {1};
         _state.voices[voice].envelopeF_Fac = _state.state.envelopeF_D_FAC;
         _state.voices[voice].envelopeF_Level = (_state.voices[voice].envelopeF_Peak * _state.state.envelopeF_Sus);
         _state.voices[voice].envelopeF_SDif = (_state.voices[voice].envelopeF_Out - _state.voices[voice].envelopeF_Level);
     }
     else
     {
         _state.voices[voice].envelopeF_Inc = (peakF_1 * _state.state.envelopeF_Att);
         _state.voices[voice].envelopeF_Peak = peakF_1;
         _state.voices[voice].envelopeF_Stage = int32_t {0};
         _state.voices[voice].envelopeF_SDif = 1.0f;
     }
 }
 _state.voices[voice].pitch = scaledPitch;
 _state.voices[voice].oscillatorA_F = Engine__pitchToFreq (_state, _state.voices[voice].pitch + _state.voices[voice].oscillatorA_Tune);
 _state.voices[voice].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[voice].pitch) + _state.voices[voice].oscillatorB_Tune);
 _state.state.unisonNote = static_cast<float> (notePitch);
        }
        _state.voices[voice].gate = static_cast<float> (vel);
        return true;
    }

    float Engine__pitchToFreq (_Engine_1_State& _state, float v) noexcept
    {
        return Engine__fastExp (_state, (v * 5.0f) + 1381.8816f);
    }

    float Engine__fastExp (_Engine_1_State& _state, float v) noexcept
    {
        int32_t  trunc;

        trunc = static_cast<int32_t> (v);
        if (trunc > int32_t {2399})
        {
 return _state.exponentLUT[int32_t {2400}];
        }
        if (trunc < int32_t {0})
        {
 return 0.0f;
        }
        return _state.exponentLUT[std__intrinsics___wrap_2401 (trunc)] + ((v - static_cast<float> (trunc)) * _state.exponentLUTSlope[std__intrinsics___wrap_2400 (trunc)]);
    }

    int32_t std__intrinsics___wrap_2401 (int32_t n) noexcept
    {
        int32_t  x;

        x = intrinsics::modulo (n, int32_t {2401});
        return (x < int32_t {0}) ? (x + int32_t {2401}) : x;
    }

    int32_t std__intrinsics___wrap_2400 (int32_t n) noexcept
    {
        int32_t  x;

        x = intrinsics::modulo (n, int32_t {2400});
        return (x < int32_t {0}) ? (x + int32_t {2400}) : x;
    }

    void _sendEvent_eventIn_2 (Pro54_State& _state, std_notes_NoteOff value) noexcept
    {
        _Pro54__eventIn_0 (_state._state, value);
    }

    void _Pro54__eventIn_0 (_Pro54_State& _state, std_notes_NoteOff value) noexcept
    {
        Engine__eventIn_0 (_state.engine, value);
    }

    void Engine__eventIn_0 (_Engine_1_State& _state, std_notes_NoteOff e) noexcept
    {
        auto _tempArg_0 = static_cast<int32_t> (e.pitch);
        Engine__noteOff (_state, _tempArg_0, static_cast<int32_t> (e.velocity * 128.0f));
    }

    void Engine__noteOff (_Engine_1_State& _state, int32_t note, int32_t vel) noexcept
    {
        int32_t  v;

        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     if (v == _state.activeVoices)
     {
         break;
     }
     if (_state.collVoiceNote[v] == note)
     {
         _state.collVoiceSustain[v] = _state.sustainActive;
         if (! (_state.collVoiceSustain[v] ? true : _state.collVoiceHold[v]))
         {
  Engine__triggerNoteOff (_state, v, vel);
  Engine__releaseVoice (_state, v);
  _state.collVoiceNote[v] = (noteOffMarker - note);
         }
     }
     {
         ++v;
     }
 }
        }
    }

    void Engine__triggerNoteOff (_Engine_1_State& _state, int32_t voice, int32_t vel) noexcept
    {
        int32_t  notePitch;
        int32_t  numActiveVoices;
        float  nearestNote;
        int32_t  v;
        int32_t  bestDiff;
        int32_t  currDiff;
        int32_t  v_0;
        int32_t  v_1;

        notePitch = _state.collVoiceNote[voice];
        _state.voices[voice].noteNumber = static_cast<float> (notePitch);
        if (_state.state.unisonActive)
        {
 if (static_cast<float> (notePitch) != _state.state.unisonNote)
 {
     _state.voices[voice].gate = 0.0f;
     return;
 }
 numActiveVoices = int32_t {0};
 nearestNote = 1000.0f;
 {
     v = {};
     for (;;)
     {
         if (v >= int32_t {32})
         {
  break;
         }
         if (v == _state.activeVoices)
         {
  break;
         }
         if (static_cast<double> (_state.voices[v].gate) > 0.0)
         {
  ++numActiveVoices;
  bestDiff = static_cast<int32_t> (static_cast<float> (notePitch) - nearestNote);
  currDiff = static_cast<int32_t> (static_cast<float> (notePitch) - _state.voices[v].noteNumber);
  if (((currDiff * currDiff) < (bestDiff * bestDiff)) ? (v != voice) : false)
  {
      nearestNote = _state.voices[v].noteNumber;
  }
         }
         {
  ++v;
         }
     }
 }
 if (static_cast<double> (_state.voices[voice].gate) > 0.0)
 {
     if (numActiveVoices == int32_t {1})
     {
         {
  v_0 = {};
  for (;;)
  {
      if (v_0 >= int32_t {32})
      {
          break;
      }
      if (v_0 == _state.activeVoices)
      {
          break;
      }
      _state.voices[v_0].envelopeA_Stage = int32_t {2};
      _state.voices[v_0].envelopeA_Fac = _state.state.envelopeA_R_FAC;
      _state.voices[v_0].envelopeA_Level = envelopeAOffset;
      _state.voices[v_0].envelopeA_SDif = (_state.voices[v_0].envelopeA_Out - _state.voices[v_0].envelopeA_Level);
      _state.voices[v_0].envelopeF_Stage = int32_t {2};
      _state.voices[v_0].envelopeF_Fac = _state.state.envelopeF_R_FAC;
      _state.voices[v_0].envelopeF_Level = 0.0f;
      _state.voices[v_0].envelopeF_SDif = (_state.voices[v_0].envelopeF_Out - _state.voices[v_0].envelopeF_Level);
      {
          ++v_0;
      }
  }
         }
         _state.state.unisonGate = 0.0f;
     }
     else
     {
         if (numActiveVoices > int32_t {1})
         {
  _state.lastUnison = static_cast<int32_t> (nearestNote);
  _state.state.unisonNote = nearestNote;
  _state.state.glideFinal = _state.state.unisonNote;
  if (_state.state.glideFinal == _state.state.glideOut)
  {
      _state.state.glideInc = 0.0f;
      {
          v_1 = {};
          for (;;)
          {
   if (v_1 >= int32_t {32})
   {
       break;
   }
   if (v_1 == _state.activeVoices)
   {
       break;
   }
   _state.voices[v_1].pitch = (_state.state.glideFinal + _state.voices[v_1].unisonRnd);
   _state.voices[v_1].oscillatorA_F = Engine__pitchToFreq (_state, _state.voices[v_1].pitch + _state.voices[v_1].oscillatorA_Tune);
   _state.voices[v_1].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[v_1].pitch) + _state.voices[v_1].oscillatorB_Tune);
   {
       ++v_1;
   }
          }
      }
  }
  else
  {
      if (_state.state.glideFinal > _state.state.glideOut)
      {
          _state.state.glideInc = ((_state.state.glide * _state.tau) * 1.0f);
      }
      else
      {
          _state.state.glideInc = (((- _state.state.glide) * _state.tau) * 1.0f);
      }
  }
         }
     }
 }
        }
        else
        {
 _state.voices[voice].envelopeA_Stage = int32_t {2};
 _state.voices[voice].envelopeA_Fac = _state.state.envelopeA_R_FAC;
 _state.voices[voice].envelopeA_Level = envelopeAOffset;
 _state.voices[voice].envelopeA_SDif = (_state.voices[voice].envelopeA_Out - _state.voices[voice].envelopeA_Level);
 _state.voices[voice].envelopeF_Stage = int32_t {2};
 _state.voices[voice].envelopeF_Fac = _state.state.envelopeF_R_FAC;
 _state.voices[voice].envelopeF_Level = 0.0f;
 _state.voices[voice].envelopeF_SDif = (_state.voices[voice].envelopeF_Out - _state.voices[voice].envelopeF_Level);
        }
        _state.voices[voice].gate = 0.0f;
    }

    void Engine__releaseVoice (_Engine_1_State& _state, int32_t v) noexcept
    {
        if (_state.youngestOffVoice == int32_t {-1})
        {
 Engine__insertBefore (_state, _state.oldestVoice & int32_t {31}, v);
 _state.oldestVoice = v;
        }
        else
        {
 Engine__insertAfter (_state, _state.youngestOffVoice & int32_t {31}, v);
        }
        _state.youngestOffVoice = v;
    }

    void _sendEvent_eventIn_3 (Pro54_State& _state, std_notes_PitchBend value) noexcept
    {
        _Pro54__eventIn_1 (_state._state, value);
    }

    void _Pro54__eventIn_1 (_Pro54_State& _state, std_notes_PitchBend value) noexcept
    {
        Engine__eventIn_1 (_state.engine, value);
    }

    void Engine__eventIn_1 (_Engine_1_State& _state, std_notes_PitchBend e) noexcept
    {
        Engine__setPitchBend (_state, 0.5f + (0.5f * (e.bendSemitones / 48.0f)));
    }

    void Engine__setPitchBend (_Engine_1_State& _state, float value) noexcept
    {
        int32_t  v;

        _state.state.pitchBend = (4.0f * (value - 0.5f));
        _state.state.tune = (_state.state.masterTune + _state.state.pitchBend);
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     _state.voices[v].oscillatorA_Tune = ((_state.state.oscillatorA_Freq + _state.voices[v].oscillatorA_Rnd) + _state.state.tune);
     _state.voices[v].oscillatorA_F = Engine__pitchToFreq (_state, _state.voices[v].pitch + _state.voices[v].oscillatorA_Tune);
     _state.voices[v].oscillatorB_Tune = ((((_state.state.oscillatorB_LOF + _state.state.oscillatorB_Pitch) + _state.state.oscillatorB_Fine) + _state.voices[v].oscillatorB_Rnd) + _state.state.tune);
     _state.voices[v].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[v].pitch) + _state.voices[v].oscillatorB_Tune);
     {
         ++v;
     }
 }
        }
    }

    void _sendEvent_eventIn_4 (Pro54_State& _state, std_notes_Control value) noexcept
    {
        _Pro54__eventIn_2 (_state._state, value);
    }

    void _Pro54__eventIn_2 (_Pro54_State& _state, std_notes_Control value) noexcept
    {
        Engine__eventIn_2 (_state.engine, value);
    }

    void Engine__eventIn_2 (_Engine_1_State& _state, std_notes_Control e) noexcept
    {
        if (e.control == int32_t {1})
        {
 Engine__setModWheel (_state, e.value);
        }
    }

    void Engine__setModWheel (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.modulationWheel = (value * static_cast<float> (int32_t {5}));
    }

    void _sendEvent_PolyModFilterEnv (Pro54_State& _state, float value) noexcept
    {
        _Pro54__PolyModFilterEnv (_state._state, value);
    }

    void _Pro54__PolyModFilterEnv (_Pro54_State& _state, float value) noexcept
    {
        Engine__PolyModFilterEnv (_state.engine, value);
    }

    void Engine__PolyModFilterEnv (_Engine_1_State& _state, float value) noexcept
    {
        float  Knob;

        value = (value * 0.01f);
        Knob = 0.4f + (4.7f * value);
        _state.state.polymodEnvelopeF = ((Knob * Knob) - 0.16f);
    }

    void _sendEvent_PolyModOscB (Pro54_State& _state, float value) noexcept
    {
        _Pro54__PolyModOscB (_state._state, value);
    }

    void _Pro54__PolyModOscB (_Pro54_State& _state, float value) noexcept
    {
        Engine__PolyModOscB (_state.engine, value);
    }

    void Engine__PolyModOscB (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.polymodOscillatorB = (3.09f * value);
    }

    void _sendEvent_PolyModFreqA (Pro54_State& _state, float value) noexcept
    {
        _Pro54__PolyModFreqA (_state._state, value);
    }

    void _Pro54__PolyModFreqA (_Pro54_State& _state, float value) noexcept
    {
        Engine__PolyModFreqA (_state.engine, value);
    }

    void Engine__PolyModFreqA (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.oscillatorA_FM_PM = ((value != static_cast<float> (int32_t {0})) ? 0.4f : 0.0f);
    }

    void _sendEvent_PolyModPWA (Pro54_State& _state, float value) noexcept
    {
        _Pro54__PolyModPWA (_state._state, value);
    }

    void _Pro54__PolyModPWA (_Pro54_State& _state, float value) noexcept
    {
        Engine__PolyModPWA (_state.engine, value);
    }

    void Engine__PolyModPWA (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.oscillatorA_PW_PM = ((value != static_cast<float> (int32_t {0})) ? -1.0f : 0.0f);
    }

    void _sendEvent_PolyModFilt (Pro54_State& _state, float value) noexcept
    {
        _Pro54__PolyModFilt (_state._state, value);
    }

    void _Pro54__PolyModFilt (_Pro54_State& _state, float value) noexcept
    {
        Engine__PolyModFilt (_state.engine, value);
    }

    void Engine__PolyModFilt (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.filter_PM = ((value != static_cast<float> (int32_t {0})) ? 3.8f : 0.0f);
    }

    void _sendEvent_OscAFreq (Pro54_State& _state, float value) noexcept
    {
        _Pro54__OscAFreq (_state._state, value);
    }

    void _Pro54__OscAFreq (_Pro54_State& _state, float value) noexcept
    {
        Engine__OscAFreq (_state.engine, value);
    }

    void Engine__OscAFreq (_Engine_1_State& _state, float value) noexcept
    {
        int32_t  v;

        value = (value * 0.01f);
        _state.state.oscillatorA_Freq = (static_cast<float> (int32_t {-24} + static_cast<int32_t> ((47.625f * value) + 0.4f)) + static_cast<float> (int32_t {12}));
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     _state.voices[v].oscillatorA_Tune = ((_state.state.oscillatorA_Freq + _state.voices[v].oscillatorA_Rnd) + _state.state.tune);
     _state.voices[v].oscillatorA_F = Engine__pitchToFreq (_state, _state.voices[v].pitch + _state.voices[v].oscillatorA_Tune);
     {
         ++v;
     }
 }
        }
    }

    void _sendEvent_OscASaw (Pro54_State& _state, float value) noexcept
    {
        _Pro54__OscASaw (_state._state, value);
    }

    void _Pro54__OscASaw (_Pro54_State& _state, float value) noexcept
    {
        Engine__OscASaw (_state.engine, value);
    }

    void Engine__OscASaw (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.oscillatorA_SawActive = ((value != static_cast<float> (int32_t {0})) ? 1.0f : 0.0f);
        _state.state.oscillatorA_SawA = (_state.state.mixerOscillatorA * _state.state.oscillatorA_SawActive);
    }

    void _sendEvent_OscAPulse (Pro54_State& _state, float value) noexcept
    {
        _Pro54__OscAPulse (_state._state, value);
    }

    void _Pro54__OscAPulse (_Pro54_State& _state, float value) noexcept
    {
        Engine__OscAPulse (_state.engine, value);
    }

    void Engine__OscAPulse (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.oscillatorA_PulseActive = (value != static_cast<float> (int32_t {0}));
    }

    void _sendEvent_OscAPW (Pro54_State& _state, float value) noexcept
    {
        _Pro54__OscAPW (_state._state, value);
    }

    void _Pro54__OscAPW (_Pro54_State& _state, float value) noexcept
    {
        Engine__OscAPW (_state.engine, value);
    }

    void Engine__OscAPW (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.oscillatorA_PW_Final = ((value * static_cast<float> (int32_t {2})) - static_cast<float> (int32_t {1}));
        Engine__smoothValue (_state);
    }

    void Engine__smoothValue (_Engine_1_State& _state) noexcept
    {
        float  factor;
        float  final_;

        _state.state.knobSmoothingCounter = knobSmoothingTime;
        factor = 0.05f;
        _state.state.mixerOscillatorA_Inc = Engine__undenormalise ((_state.state.mixerOscillatorA_Final - _state.state.mixerOscillatorA) * factor);
        _state.state.mixerOscillatorB_Inc = Engine__undenormalise ((_state.state.mixerOscillatorB_Final - _state.state.mixerOscillatorB) * factor);
        _state.state.oscillatorA_PW_Inc = Engine__undenormalise ((_state.state.oscillatorA_PW_Final - _state.state.oscillatorA_PW) * factor);
        _state.state.oscillatorB_PW_Inc = Engine__undenormalise ((_state.state.oscillatorB_PW_Final - _state.state.oscillatorB_PW) * factor);
        _state.state.filter_EnvInc = Engine__undenormalise ((_state.state.filterEnvelopeFinal - _state.state.filter_Env) * factor);
        _state.state.filter_KeyboardInc = Engine__undenormalise ((_state.state.filterKeyboardFinal - _state.state.filter_Keyboard) * factor);
        final_ = ((35.0f * (1.0f - _state.state.filterKeyboardFinal)) + _state.state.filter_Cutoff) + (4.5f * _state.state.filter_Res);
        _state.state.filter_EventInc = Engine__undenormalise ((final_ - _state.state.filter_Event) * 0.05f);
    }

    float Engine__undenormalise (float f) noexcept
    {
        return ((-1e-12 < static_cast<double> (f)) ? (static_cast<double> (f) < 1e-12) : false) ? 0.0f : f;
    }

    void _sendEvent_OscASync (Pro54_State& _state, float value) noexcept
    {
        _Pro54__OscASync (_state._state, value);
    }

    void _Pro54__OscASync (_Pro54_State& _state, float value) noexcept
    {
        Engine__OscASync (_state.engine, value);
    }

    void Engine__OscASync (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.oscillatorSyncActive = (value > 0.0f);
    }

    void _sendEvent_MixerOscALevel (Pro54_State& _state, float value) noexcept
    {
        _Pro54__MixerOscALevel (_state._state, value);
    }

    void _Pro54__MixerOscALevel (_Pro54_State& _state, float value) noexcept
    {
        Engine__MixerOscALevel (_state.engine, value);
    }

    void Engine__MixerOscALevel (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.mixerOscillatorA_Final = value;
        Engine__smoothValue (_state);
    }

    void _sendEvent_MixerOscBLevel (Pro54_State& _state, float value) noexcept
    {
        _Pro54__MixerOscBLevel (_state._state, value);
    }

    void _Pro54__MixerOscBLevel (_Pro54_State& _state, float value) noexcept
    {
        Engine__MixerOscBLevel (_state.engine, value);
    }

    void Engine__MixerOscBLevel (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.mixerOscillatorB_Final = (2.0f * value);
        Engine__smoothValue (_state);
    }

    void _sendEvent_MixerNoiseLevel (Pro54_State& _state, float value) noexcept
    {
        _Pro54__MixerNoiseLevel (_state._state, value);
    }

    void _Pro54__MixerNoiseLevel (_Pro54_State& _state, float value) noexcept
    {
        Engine__MixerNoiseLevel (_state.engine, value);
    }

    void Engine__MixerNoiseLevel (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.mixerNoise = (1.75f * value);
    }

    void _sendEvent_ExternalInputLevel (Pro54_State& _state, float value) noexcept
    {
        _Pro54__ExternalInputLevel (_state._state, value);
    }

    void _Pro54__ExternalInputLevel (_Pro54_State& _state, float value) noexcept
    {
        Engine__ExternalInputLevel (_state.engine, value);
    }

    void Engine__ExternalInputLevel (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.mixerExternal = (inputVolume * value);
    }

    void _sendEvent_FilterCutoff (Pro54_State& _state, float value) noexcept
    {
        _Pro54__FilterCutoff (_state._state, value);
    }

    void _Pro54__FilterCutoff (_Pro54_State& _state, float value) noexcept
    {
        Engine__FilterCutoff (_state.engine, value);
    }

    void Engine__FilterCutoff (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.filter_Cutoff = (-39.0f + static_cast<float> (static_cast<int32_t> (120.0f * value)));
        Engine__smoothValue (_state);
    }

    float normalizeGetFilterCutoff (float value) const noexcept
    {
      // Reverse the calculation from FilterCutoff:
      // (_state.state.filter_Cutoff + 39.0f) / 120.0f gives normalized 0-1 value
      // Multiply by 100 to match original percentage scale
      return ((value + 39.0f) / 120.0f) * 100.0f;
    }

    void _sendEvent_FilterResonance (Pro54_State& _state, float value) noexcept
    {
        _Pro54__FilterResonance (_state._state, value);
    }

    void _Pro54__FilterResonance (_Pro54_State& _state, float value) noexcept
    {
        Engine__FilterResonance (_state.engine, value);
    }

    void Engine__FilterResonance (_Engine_1_State& _state, float value) noexcept
    {
        float  Res;

        value = (value * 0.01f);
        _state.state.filter_Res = value;
        Res = {};
        if (static_cast<double> (_state.state.filter_Res) < 0.25)
        {
 Res = (2.32f * _state.state.filter_Res);
        }
        else
        {
 if (_state.state.filter_Res < 0.5f)
 {
     Res = ((0.52f * _state.state.filter_Res) + 0.45f);
 }
 else
 {
     if (_state.state.filter_Res < 0.75f)
     {
         Res = ((0.92f * _state.state.filter_Res) + 0.25f);
     }
     else
     {
         Res = ((0.036f * _state.state.filter_Res) + 0.913f);
     }
 }
        }
        _state.state.filter_D = (2.0f - (2.0f * Res));
        _state.state.filter_K = (4.1f * value);
        if (_state.state.filter_HPF)
        {
 _state.state.filter_FMAX = (0.5f + ((0.0318f * Res) * (27.5989f + Res)));
        }
        else
        {
 _state.state.filter_FMAX = (0.7352f + ((0.293f * Res) * (1.3075f + Res)));
        }
        Res = (Res * 0.8f);
        _state.state.filterN_D = (2.0f - (2.0f * Res));
        if (_state.state.filter_HPF)
        {
 _state.state.filterN_FMAX = (0.5f + ((0.0318f * Res) * (27.5989f + Res)));
        }
        else
        {
 _state.state.filterN_FMAX = (0.7352f + ((0.293f * Res) * (1.3075f + Res)));
        }
        Engine__smoothValue (_state);
    }

    void _sendEvent_FilterEnvAmt (Pro54_State& _state, float value) noexcept
    {
        _Pro54__FilterEnvAmt (_state._state, value);
    }

    void _Pro54__FilterEnvAmt (_Pro54_State& _state, float value) noexcept
    {
        Engine__FilterEnvAmt (_state.engine, value);
    }

    void Engine__FilterEnvAmt (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.filterEnvelopeFinal = ((_state.state.filterEnvelopeInv * 192.0f) * value);
        Engine__smoothValue (_state);
    }

    void _sendEvent_FilterKeyboardTracking (Pro54_State& _state, float value) noexcept
    {
        _Pro54__FilterKeyboardTracking (_state._state, value);
    }

    void _Pro54__FilterKeyboardTracking (_Pro54_State& _state, float value) noexcept
    {
        Engine__FilterKeyboardTracking (_state.engine, value);
    }

    void Engine__FilterKeyboardTracking (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.filterKeyboardFinal = (value * 0.01f);
        Engine__smoothValue (_state);
    }

    void _sendEvent_FilterAttack (Pro54_State& _state, float value) noexcept
    {
        _Pro54__FilterAttack (_state._state, value);
    }

    void _Pro54__FilterAttack (_Pro54_State& _state, float value) noexcept
    {
        Engine__FilterAttack (_state.engine, value);
    }

    void Engine__FilterAttack (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.envelopeF_Att = (_state.tau * Engine__timeToIncrement (_state, -5.0f + (90.7f * value)));
    }

    float Engine__timeToIncrement (_Engine_1_State& _state, float v) noexcept
    {
        return Engine__fastExp (_state, 1797.947f - (v * 9.965784f));
    }

    void _sendEvent_FilterDecay (Pro54_State& _state, float value) noexcept
    {
        _Pro54__FilterDecay (_state._state, value);
    }

    void _Pro54__FilterDecay (_Pro54_State& _state, float value) noexcept
    {
        Engine__FilterDecay (_state.engine, value);
    }

    void Engine__FilterDecay (_Engine_1_State& _state, float value) noexcept
    {
        float  factor;
        int32_t  v;

        value = (value * 0.01f);
        factor = Engine__timeToIncrement (_state, -3.0f + (85.0f * value)) * _state.tau;
        if (static_cast<double> (factor) > 1.0)
        {
 _state.state.envelopeF_D_FAC = 0.0f;
        }
        else
        {
 _state.state.envelopeF_D_FAC = (1.0f - factor);
        }
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     if (_state.voices[v].envelopeF_Stage == int32_t {1})
     {
         _state.voices[v].envelopeF_Fac = _state.state.envelopeF_D_FAC;
     }
     {
         ++v;
     }
 }
        }
    }

    void _sendEvent_FilterSustain (Pro54_State& _state, float value) noexcept
    {
        _Pro54__FilterSustain (_state._state, value);
    }

    void _Pro54__FilterSustain (_Pro54_State& _state, float value) noexcept
    {
        Engine__FilterSustain (_state.engine, value);
    }

    void Engine__FilterSustain (_Engine_1_State& _state, float value) noexcept
    {
        int32_t  v;

        value = (value * 0.01f);
        _state.state.envelopeF_Sus = (0.98f * value);
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     if (_state.voices[v].envelopeF_Stage == int32_t {1})
     {
         _state.voices[v].envelopeF_Level = (_state.state.envelopeF_Sus * _state.voices[v].envelopeF_Peak);
         _state.voices[v].envelopeF_SDif = (_state.voices[v].envelopeF_Out - _state.voices[v].envelopeF_Level);
     }
     {
         ++v;
     }
 }
        }
    }

    void _sendEvent_FilterRelease (Pro54_State& _state, float value) noexcept
    {
        _Pro54__FilterRelease (_state._state, value);
    }

    void _Pro54__FilterRelease (_Pro54_State& _state, float value) noexcept
    {
        Engine__FilterRelease (_state.engine, value);
    }

    void Engine__FilterRelease (_Engine_1_State& _state, float value) noexcept
    {
        float  factor;
        int32_t  v;

        value = (value * 0.01f);
        _state.state.envelopeF_Rel = (-10.0f + (92.7f * value));
        factor = Engine__timeToIncrement (_state, _state.state.envelopeRelease * _state.state.envelopeF_Rel) * _state.tau;
        if (static_cast<double> (factor) > 1.0)
        {
 _state.state.envelopeF_R_FAC = 0.0f;
        }
        else
        {
 _state.state.envelopeF_R_FAC = (1.0f - factor);
        }
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     if (_state.voices[v].envelopeF_Stage == int32_t {2})
     {
         _state.voices[v].envelopeF_Fac = _state.state.envelopeF_R_FAC;
     }
     {
         ++v;
     }
 }
        }
    }

    void _sendEvent_DelayTime (Pro54_State& _state, float value) noexcept
    {
        _Pro54__DelayTime (_state._state, value);
    }

    void _Pro54__DelayTime (_Pro54_State& _state, float value) noexcept
    {
        Engine__DelayTime (_state.engine, value);
    }

    void Engine__DelayTime (_Engine_1_State& _state, float value) noexcept
    {
        float  octave;
        int32_t  octaveInt;

        value = (value * 0.01f);
        octave = -8.97f + (9.97f * value);
        octaveInt = static_cast<int32_t> (intrinsics::floor (octave));
        _state.state.delayTimeRatio = (0.001953125f * static_cast<float> (int32_t {1} << (octaveInt + int32_t {9})));
        _state.state.delayTimeRatio = (_state.state.delayTimeRatio * 60.0f);
        if (static_cast<double> (octave - static_cast<float> (octaveInt)) > 0.58)
        {
 _state.state.delayTimeRatio = (_state.state.delayTimeRatio * 1.5f);
        }
        if (_state.state.delayMIDI == static_cast<float> (int32_t {0}))
        {
 _state.state.delayTime = Engine__exp_dB (_state, -60.0f + (60.0f * value));
        }
        Engine__computeDelayTimes (_state);
    }

    float std__intrinsics__floor (float n) noexcept
    {
        float  rounded;

        rounded = static_cast<float> (static_cast<int64_t> (n));
        if (rounded == n)
        {
 return n;
        }
        if (n >= static_cast<float> (int32_t {0}))
        {
 return rounded;
        }
        return rounded - static_cast<float> (int32_t {1});
    }

    float Engine__exp_dB (_Engine_1_State& _state, float v) noexcept
    {
        return Engine__fastExp (_state, (v * 9.965784f) + 1200.0f);
    }

    void Engine__computeDelayTimes (_Engine_1_State& _state) noexcept
    {
        float  time;
        float  timeLimit;

        time = static_cast<float> (static_cast<int32_t> ((static_cast<double> (_state.state.delayTime) * (1.0 * _frequency)) + 0.5));
        if (_state.state.delaySync)
        {
 _state.state.delayTime_1 = (time * (1.0f - _state.state.delaySpread));
 _state.state.delayTime_2 = (time * (1.0f - (0.5f * _state.state.delaySpread)));
 _state.state.delayTime_3 = (time * (1.0f + (0.5f * _state.state.delaySpread)));
 _state.state.delayTime_4 = (time * (1.0f + _state.state.delaySpread));
        }
        else
        {
 _state.state.delayTime_1 = (time * (1.0f - _state.state.delaySpread));
 _state.state.delayTime_2 = (time * (1.0f - (0.4f * _state.state.delaySpread)));
 _state.state.delayTime_3 = (time * (1.0f + (0.5f * _state.state.delaySpread)));
 _state.state.delayTime_4 = (time * (1.0f + (0.9f * _state.state.delaySpread)));
        }
        if (_state.state.delayTime_1 < _state.state.delayDepth)
        {
 _state.state.delayTime_1 = _state.state.delayDepth;
        }
        if (_state.state.delayTime_2 < _state.state.delayDepth)
        {
 _state.state.delayTime_2 = _state.state.delayDepth;
        }
        if (_state.state.delayTime_3 < _state.state.delayDepth)
        {
 _state.state.delayTime_3 = _state.state.delayDepth;
        }
        if (_state.state.delayTime_4 < _state.state.delayDepth)
        {
 _state.state.delayTime_4 = _state.state.delayDepth;
        }
        timeLimit = static_cast<float> (int32_t {0x1ffff}) - _state.state.delayDepth;
        if (_state.state.delayTime_1 > timeLimit)
        {
 _state.state.delayTime_1 = timeLimit;
        }
        if (_state.state.delayTime_2 > timeLimit)
        {
 _state.state.delayTime_2 = timeLimit;
        }
        if (_state.state.delayTime_3 > timeLimit)
        {
 _state.state.delayTime_3 = timeLimit;
        }
        if (_state.state.delayTime_4 > timeLimit)
        {
 _state.state.delayTime_4 = timeLimit;
        }
    }

    void _sendEvent_DelaySpread (Pro54_State& _state, float value) noexcept
    {
        _Pro54__DelaySpread (_state._state, value);
    }

    void _Pro54__DelaySpread (_Pro54_State& _state, float value) noexcept
    {
        Engine__DelaySpread (_state.engine, value);
    }

    void Engine__DelaySpread (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.delaySpread = value;
        Engine__computeDelayTimes (_state);
    }

    void _sendEvent_DelayDepth (Pro54_State& _state, float value) noexcept
    {
        _Pro54__DelayDepth (_state._state, value);
    }

    void _Pro54__DelayDepth (_Pro54_State& _state, float value) noexcept
    {
        Engine__DelayDepth (_state.engine, value);
    }

    void Engine__DelayDepth (_Engine_1_State& _state, float value) noexcept
    {
        float  _temp;

        value = (value * 0.01f);
        if (value > static_cast<float> (int32_t {0}))
        {
 _temp = (Engine__exp_E (_state, 5.0f * value) * 0.000185f);
        }
        else
        {
 _temp = 0.0f;
        }
        _state.state.delayDepthKnob = _temp;
        _state.state.delayDepth = (_state.state.delayDepthKnob * static_cast<float> (1.0 * _frequency));
        Engine__computeDelayTimes (_state);
    }

    float Engine__exp_E (_Engine_1_State& _state, float v) noexcept
    {
        return Engine__fastExp (_state, (v * 86.5617f) + 1200.0f);
    }

    void _sendEvent_DelayRate (Pro54_State& _state, float value) noexcept
    {
        _Pro54__DelayRate (_state._state, value);
    }

    void _Pro54__DelayRate (_Pro54_State& _state, float value) noexcept
    {
        Engine__DelayRate (_state.engine, value);
    }

    void Engine__DelayRate (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.delayRate = Engine__pitchToFreq (_state, static_cast<float> (int32_t {-60}) + (80.0f * value));
        if (_state.state.delaySync)
        {
 _state.state.delayRate_1 = _state.state.delayRate;
        }
        else
        {
 _state.state.delayRate_1 = (_state.state.delayRate * 1.029f);
 _state.state.delayRate_2 = (_state.state.delayRate * 0.917f);
 _state.state.delayRate_3 = (_state.state.delayRate * 0.972f);
 _state.state.delayRate_4 = (_state.state.delayRate * 1.091f);
        }
    }

    void _sendEvent_DelayFeedback (Pro54_State& _state, float value) noexcept
    {
        _Pro54__DelayFeedback (_state._state, value);
    }

    void _Pro54__DelayFeedback (_Pro54_State& _state, float value) noexcept
    {
        Engine__DelayFeedback (_state.engine, value);
    }

    void Engine__DelayFeedback (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.delayFeedbackKnob = (value * 0.25f);
        _state.state.delayFeedbackFinal = ((_state.state.delayFeedbackKnob * _state.state.delayInv) * (1.0f - (0.5f * _state.state.delay_HPF_F)));
        Engine__smoother (_state);
    }

    void Engine__smoother (_Engine_1_State& _state) noexcept
    {
        float  factor;

        _state.state.smootherCount = static_cast<int32_t> (0.02 * (1.0 * _frequency));
        factor = 1.0f / static_cast<float> (_state.state.smootherCount);
        _state.state.volumeInc = Engine__undenormalise ((_state.state.volumeFinal - _state.state.volumeSmooth) * factor);
        _state.state.delayWetInc = Engine__undenormalise ((_state.state.delayWetFinal - _state.state.delayWetSmooth) * factor);
        _state.state.delayDryInc = Engine__undenormalise ((_state.state.delayDryFinal - _state.state.delayDrySmooth) * factor);
        _state.state.delayFeedbackInc = Engine__undenormalise ((_state.state.delayFeedbackFinal - _state.state.delayFeedbackSmooth) * factor);
    }

    void _sendEvent_DelayHiCut (Pro54_State& _state, float value) noexcept
    {
        _Pro54__DelayHiCut (_state._state, value);
    }

    void _Pro54__DelayHiCut (_Pro54_State& _state, float value) noexcept
    {
        Engine__DelayHiCut (_state.engine, value);
    }

    void Engine__DelayHiCut (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.delay_HPF_F = intrinsics::min (0.99f, Engine__pitchToFreq (_state, 0.0f + (120.0f * value)) * _state.tauFilter);
        _state.state.delayFeedbackFinal = ((_state.state.delayFeedbackKnob * _state.state.delayInv) * (1.0f - (0.5f * _state.state.delay_HPF_F)));
        Engine__smoother (_state);
    }

    float std__intrinsics__min (float v1, float v2) noexcept
    {
        {
 return (v1 < v2) ? v1 : v2;
        }
    }

    void _sendEvent_DelayLoCut (Pro54_State& _state, float value) noexcept
    {
        _Pro54__DelayLoCut (_state._state, value);
    }

    void _Pro54__DelayLoCut (_Pro54_State& _state, float value) noexcept
    {
        Engine__DelayLoCut (_state.engine, value);
    }

    void Engine__DelayLoCut (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.delay_LPF_F = intrinsics::min (0.99f, Engine__pitchToFreq (_state, 40.0f + (80.0f * value)) * _state.tauFilter);
    }

    void _sendEvent_DelayINV (Pro54_State& _state, float value) noexcept
    {
        _Pro54__DelayINV (_state._state, value);
    }

    void _Pro54__DelayINV (_Pro54_State& _state, float value) noexcept
    {
        Engine__DelayINV (_state.engine, value);
    }

    void Engine__DelayINV (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.delayInv = ((static_cast<double> (value) >= 0.5) ? -1.0f : 1.0f);
        _state.state.delayFeedbackFinal = ((_state.state.delayFeedbackKnob * _state.state.delayInv) * (1.0f - (0.5f * _state.state.delay_HPF_F)));
        _state.state.delayWetFinal = (((_state.state.delayWetKnob * (1.828f - (0.828f * _state.state.delayWetKnob))) * 0.5f) * _state.state.delayInv);
        Engine__smoother (_state);
    }

    void _sendEvent_DelayON (Pro54_State& _state, float value) noexcept
    {
        _Pro54__DelayON (_state._state, value);
    }

    void _Pro54__DelayON (_Pro54_State& _state, float value) noexcept
    {
        Engine__DelayON (_state.engine, value);
    }

    void Engine__DelayON (_Engine_1_State& _state, float value) noexcept
    {
        if (static_cast<double> (value) < 0.5)
        {
 _state.state.delayActive = false;
 _state.state.delayWetFinal = 0.0f;
 _state.state.delayDryFinal = 1.0f;
 Engine__smoother (_state);
        }
        else
        {
 if (! _state.state.delayActive)
 {
     _state.state.delayActive = true;
     _state.state.delayWetFinal = (((_state.state.delayWetKnob * (1.828f - (0.828f * _state.state.delayWetKnob))) * 0.5f) * _state.state.delayInv);
     _state.state.delayDryFinal = ((1.0f - _state.state.delayWetKnob) * (1.828f - (0.828f * (1.0f - _state.state.delayWetKnob))));
     Engine__smoother (_state);
     _state.state.delaySum = 0.0f;
     _state.state.delay_HPF_LPF = 0.0f;
     _state.state.delay_LPF_LPF = 0.0f;
     _state.state.delayTime_Inc_1 = 0.0f;
     _state.state.delayTime_Inc_2 = 0.0f;
     _state.state.delayTime_Inc_3 = 0.0f;
     _state.state.delayTime_Inc_4 = 0.0f;
     _state.state.delayLFO_Pos_1 = 0.0f;
     _state.state.delayLFO_Pos_2 = 0.0f;
     _state.state.delayLFO_Pos_3 = 0.0f;
     _state.state.delayLFO_Pos_4 = 0.0f;
     _state.state.delayTime_Mod_1 = _state.state.delayTime_1;
     _state.state.delayTime_Mod_2 = _state.state.delayTime_2;
     _state.state.delayTime_Mod_3 = _state.state.delayTime_3;
     _state.state.delayTime_Mod_4 = _state.state.delayTime_4;
     _state.delayBuffer = __constant_;
 }
        }
    }

    void _sendEvent_DelayWet (Pro54_State& _state, float value) noexcept
    {
        _Pro54__DelayWet (_state._state, value);
    }

    void _Pro54__DelayWet (_Pro54_State& _state, float value) noexcept
    {
        Engine__DelayWet (_state.engine, value);
    }

    void Engine__DelayWet (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.delayWetKnob = value;
        if (_state.state.delayActive)
        {
 _state.state.delayWetFinal = (((_state.state.delayWetKnob * (1.828f - (0.828f * _state.state.delayWetKnob))) * 0.5f) * _state.state.delayInv);
 _state.state.delayDryFinal = ((1.0f - _state.state.delayWetKnob) * (1.828f - (0.828f * (1.0f - _state.state.delayWetKnob))));
 Engine__smoother (_state);
        }
    }

    void _sendEvent_DelaySync (Pro54_State& _state, float value) noexcept
    {
        _Pro54__DelaySync (_state._state, value);
    }

    void _Pro54__DelaySync (_Pro54_State& _state, float value) noexcept
    {
        Engine__DelaySync (_state.engine, value);
    }

    void Engine__DelaySync (_Engine_1_State& _state, float value) noexcept
    {
        if (static_cast<double> (value) >= 0.5)
        {
 _state.state.delaySync = true;
 _state.state.delayRate_1 = _state.state.delayRate;
        }
        else
        {
 _state.state.delaySync = false;
 _state.state.delayRate_1 = (_state.state.delayRate * 1.029f);
 _state.state.delayRate_2 = (_state.state.delayRate * 0.917f);
 _state.state.delayRate_3 = (_state.state.delayRate * 0.972f);
 _state.state.delayRate_4 = (_state.state.delayRate * 1.091f);
 _state.state.delayLFO_Pos_2 = _state.state.delayLFO_Pos_1;
 _state.state.delayLFO_Pos_3 = _state.state.delayLFO_Pos_1;
 _state.state.delayLFO_Pos_4 = _state.state.delayLFO_Pos_1;
        }
        Engine__computeDelayTimes (_state);
    }

    void _sendEvent_DelayMidi (Pro54_State& _state, float value) noexcept
    {
        _Pro54__DelayMidi (_state._state, value);
    }

    void _Pro54__DelayMidi (_Pro54_State& _state, float value) noexcept
    {
        Engine__DelayMidi (_state.engine, value);
    }

    void Engine__DelayMidi (_Engine_1_State& _state, float value) noexcept
    {
        if (static_cast<double> (value) >= 0.5)
        {
 _state.state.delayMIDI = 1.0f;
        }
        else
        {
 if (_state.state.delayMIDI != static_cast<float> (int32_t {0}))
 {
     _state.state.delayMIDI = 0.0f;
     _state.state.delayTime = (_state.state.delayTimeRatio / 120.0f);
     Engine__computeDelayTimes (_state);
 }
        }
    }

    void _sendEvent_LfoMidiSync (Pro54_State& _state, float value) noexcept
    {
        _Pro54__LfoMidiSync (_state._state, value);
    }

    void _Pro54__LfoMidiSync (_Pro54_State& _state, float value) noexcept
    {
        Engine__LfoMidiSync (_state.engine, value);
    }

    void Engine__LfoMidiSync (_Engine_1_State& _state, float value) noexcept
    {
        if ((value == static_cast<float> (int32_t {0})) ? static_cast<bool> (_state.state.midiTempo) : false)
        {
 _state.state.lfoFreq = (2.0f * _state.state.lfoRatio);
        }
        _state.state.midiTempo = value;
    }

    void _sendEvent_LfoFrequency (Pro54_State& _state, float value) noexcept
    {
        _Pro54__LfoFrequency (_state._state, value);
    }

    void _Pro54__LfoFrequency (_Pro54_State& _state, float value) noexcept
    {
        Engine__LfoFrequency (_state.engine, value);
    }

    void Engine__LfoFrequency (_Engine_1_State& _state, float value) noexcept
    {
        float  octave;
        int32_t  octaveInt;
        float  pitch;

        value = (value * 0.01f);
        octave = -5.5f + (9.725f * value);
        octaveInt = static_cast<int32_t> (intrinsics::floor (octave));
        _state.state.lfoRatio = (0.015625f * static_cast<float> (int32_t {1} << (octaveInt + int32_t {6})));
        if (static_cast<double> (octave - static_cast<float> (octaveInt)) > 0.58)
        {
 _state.state.lfoRatio = (_state.state.lfoRatio * 1.5f);
        }
        if (_state.state.midiTempo == static_cast<float> (int32_t {0}))
        {
 pitch = -92.7f + (116.7f * value);
 _state.state.lfoFreq = Engine__pitchToFreq (_state, pitch);
        }
    }

    void _sendEvent_LfoShapeSaw (Pro54_State& _state, float value) noexcept
    {
        _Pro54__LfoShapeSaw (_state._state, value);
    }

    void _Pro54__LfoShapeSaw (_Pro54_State& _state, float value) noexcept
    {
        Engine__LfoShapeSaw (_state.engine, value);
    }

    void Engine__LfoShapeSaw (_Engine_1_State& _state, float value) noexcept
    {
        if (value != static_cast<float> (int32_t {0}))
        {
 _state.state.lfoConst = 0.0f;
 if (static_cast<double> (_state.state.lfoShA) == 0.0)
 {
     _state.state.lfoSawA = 0.4f;
     if ((static_cast<double> (_state.state.lfoPulseA) != 0.0) ? (static_cast<double> (_state.state.lfoTriangleA) != 0.0) : false)
     {
         _state.state.lfoShA = 1.0f;
         _state.state.lfoTriangleA = 0.0f;
         _state.state.lfoPulseA = 0.0f;
         _state.state.lfoSawA = 0.0f;
     }
 }
        }
        else
        {
 _state.state.lfoSawA = 0.0f;
 if (static_cast<double> (_state.state.lfoShA) != 0.0)
 {
     _state.state.lfoShA = 0.0f;
     _state.state.lfoPulseA = 0.4f;
     _state.state.lfoTriangleA = 0.4f;
 }
 else
 {
     if ((static_cast<double> (_state.state.lfoPulseA) == 0.0) ? (static_cast<double> (_state.state.lfoTriangleA) == 0.0) : false)
     {
         _state.state.lfoConst = 0.4f;
     }
 }
        }
    }

    void _sendEvent_LfoShapeTri (Pro54_State& _state, float value) noexcept
    {
        _Pro54__LfoShapeTri (_state._state, value);
    }

    void _Pro54__LfoShapeTri (_Pro54_State& _state, float value) noexcept
    {
        Engine__LfoShapeTri (_state.engine, value);
    }

    void Engine__LfoShapeTri (_Engine_1_State& _state, float value) noexcept
    {
        if (value != static_cast<float> (int32_t {0}))
        {
 _state.state.lfoConst = 0.0f;
 if (static_cast<double> (_state.state.lfoShA) == 0.0)
 {
     _state.state.lfoTriangleA = 0.4f;
     if ((static_cast<double> (_state.state.lfoPulseA) != 0.0) ? (static_cast<double> (_state.state.lfoSawA) != 0.0) : false)
     {
         _state.state.lfoShA = 1.0f;
         _state.state.lfoTriangleA = 0.0f;
         _state.state.lfoPulseA = 0.0f;
         _state.state.lfoSawA = 0.0f;
     }
 }
        }
        else
        {
 _state.state.lfoTriangleA = 0.0f;
 if (static_cast<double> (_state.state.lfoShA) != 0.0)
 {
     _state.state.lfoShA = 0.0f;
     _state.state.lfoPulseA = 0.4f;
     _state.state.lfoSawA = 0.4f;
 }
 else
 {
     if ((static_cast<double> (_state.state.lfoPulseA) == 0.0) ? (static_cast<double> (_state.state.lfoSawA) == 0.0) : false)
     {
         _state.state.lfoConst = 0.4f;
     }
 }
        }
    }

    void _sendEvent_LfoShapePulse (Pro54_State& _state, float value) noexcept
    {
        _Pro54__LfoShapePulse (_state._state, value);
    }

    void _Pro54__LfoShapePulse (_Pro54_State& _state, float value) noexcept
    {
        Engine__LfoShapePulse (_state.engine, value);
    }

    void Engine__LfoShapePulse (_Engine_1_State& _state, float value) noexcept
    {
        if (value != static_cast<float> (int32_t {0}))
        {
 _state.state.lfoConst = 0.0f;
 if (static_cast<double> (_state.state.lfoShA) == 0.0)
 {
     _state.state.lfoPulseA = 0.4f;
     if ((static_cast<double> (_state.state.lfoTriangleA) != 0.0) ? (static_cast<double> (_state.state.lfoSawA) != 0.0) : false)
     {
         _state.state.lfoShA = 1.0f;
         _state.state.lfoTriangleA = 0.0f;
         _state.state.lfoPulseA = 0.0f;
         _state.state.lfoSawA = 0.0f;
     }
 }
        }
        else
        {
 _state.state.lfoPulseA = 0.0f;
 if (static_cast<double> (_state.state.lfoShA) != 0.0)
 {
     _state.state.lfoShA = 0.0f;
     _state.state.lfoTriangleA = 0.4f;
     _state.state.lfoSawA = 0.4f;
 }
 else
 {
     if ((static_cast<double> (_state.state.lfoTriangleA) == 0.0) ? (static_cast<double> (_state.state.lfoSawA) == 0.0) : false)
     {
         _state.state.lfoConst = 0.4f;
     }
 }
        }
        _state.state.lfoPulseA = ((value != static_cast<float> (int32_t {0})) ? 0.4f : 0.0f);
    }

    void _sendEvent_OscBFreq (Pro54_State& _state, float value) noexcept
    {
        _Pro54__OscBFreq (_state._state, value);
    }

    void _Pro54__OscBFreq (_Pro54_State& _state, float value) noexcept
    {
        Engine__OscBFreq (_state.engine, value);
    }

    void Engine__OscBFreq (_Engine_1_State& _state, float value) noexcept
    {
        int32_t  v;

        value = (value * 0.01f);
        _state.state.oscillatorB_Freq = (47.625f * value);
        _state.state.oscillatorB_Pitch = ((23.0f - (35.0f * _state.state.oscillatorB_Keyboard)) + static_cast<float> (static_cast<int32_t> ((2.0f - _state.state.oscillatorB_Keyboard) * (_state.state.oscillatorB_Freq + 0.4f))));
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     _state.voices[v].oscillatorB_Tune = ((((_state.state.oscillatorB_LOF + _state.state.oscillatorB_Pitch) + _state.state.oscillatorB_Fine) + _state.voices[v].oscillatorB_Rnd) + _state.state.tune);
     _state.voices[v].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[v].pitch) + _state.voices[v].oscillatorB_Tune);
     {
         ++v;
     }
 }
        }
    }

    void _sendEvent_OscBFreqFine (Pro54_State& _state, float value) noexcept
    {
        _Pro54__OscBFreqFine (_state._state, value);
    }

    void _Pro54__OscBFreqFine (_Pro54_State& _state, float value) noexcept
    {
        Engine__OscBFreqFine (_state.engine, value);
    }

    void Engine__OscBFreqFine (_Engine_1_State& _state, float value) noexcept
    {
        int32_t  v;

        value = (value * 0.01f);
        _state.state.oscillatorB_Fine = (0.015f + (0.935f * value));
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     _state.voices[v].oscillatorB_Tune = ((((_state.state.oscillatorB_LOF + _state.state.oscillatorB_Pitch) + _state.state.oscillatorB_Fine) + _state.voices[v].oscillatorB_Rnd) + _state.state.tune);
     _state.voices[v].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[v].pitch) + _state.voices[v].oscillatorB_Tune);
     {
         ++v;
     }
 }
        }
    }

    void _sendEvent_OscBShapeSaw (Pro54_State& _state, float value) noexcept
    {
        _Pro54__OscBShapeSaw (_state._state, value);
    }

    void _Pro54__OscBShapeSaw (_Pro54_State& _state, float value) noexcept
    {
        Engine__OscBShapeSaw (_state.engine, value);
    }

    void Engine__OscBShapeSaw (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.oscillatorB_SawA = ((value != static_cast<float> (int32_t {0})) ? 0.5f : 0.0f);
    }

    void _sendEvent_OscBShapeTri (Pro54_State& _state, float value) noexcept
    {
        _Pro54__OscBShapeTri (_state._state, value);
    }

    void _Pro54__OscBShapeTri (_Pro54_State& _state, float value) noexcept
    {
        Engine__OscBShapeTri (_state.engine, value);
    }

    void Engine__OscBShapeTri (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.oscillatorB_TriA = (value != static_cast<float> (int32_t {0}));
    }

    void _sendEvent_OscBShapePulse (Pro54_State& _state, float value) noexcept
    {
        _Pro54__OscBShapePulse (_state._state, value);
    }

    void _Pro54__OscBShapePulse (_Pro54_State& _state, float value) noexcept
    {
        Engine__OscBShapePulse (_state.engine, value);
    }

    void Engine__OscBShapePulse (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.oscillatorB_PulseA = ((value != static_cast<float> (int32_t {0})) ? 1.0f : 0.0f);
    }

    void _sendEvent_OscBPWAmount (Pro54_State& _state, float value) noexcept
    {
        _Pro54__OscBPWAmount (_state._state, value);
    }

    void _Pro54__OscBPWAmount (_Pro54_State& _state, float value) noexcept
    {
        Engine__OscBPWAmount (_state.engine, value);
    }

    void Engine__OscBPWAmount (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.oscillatorB_PW_Final = ((value * static_cast<float> (int32_t {2})) - static_cast<float> (int32_t {1}));
        Engine__smoothValue (_state);
    }

    void _sendEvent_OscBSubOsc (Pro54_State& _state, float value) noexcept
    {
        _Pro54__OscBSubOsc (_state._state, value);
    }

    void _Pro54__OscBSubOsc (_Pro54_State& _state, float value) noexcept
    {
        Engine__OscBSubOsc (_state.engine, value);
    }

    void Engine__OscBSubOsc (_Engine_1_State& _state, float value) noexcept
    {
        int32_t  v;

        _state.state.oscillatorB_LOF = ((value != static_cast<float> (int32_t {0})) ? -91.3f : 0.0f);
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     _state.voices[v].oscillatorB_Tune = ((((_state.state.oscillatorB_LOF + _state.state.oscillatorB_Pitch) + _state.state.oscillatorB_Fine) + _state.voices[v].oscillatorB_Rnd) + _state.state.tune);
     _state.voices[v].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[v].pitch) + _state.voices[v].oscillatorB_Tune);
     {
         ++v;
     }
 }
        }
    }

    void _sendEvent_OscBKKeyboardTracking (Pro54_State& _state, float value) noexcept
    {
        _Pro54__OscBKKeyboardTracking (_state._state, value);
    }

    void _Pro54__OscBKKeyboardTracking (_Pro54_State& _state, float value) noexcept
    {
        Engine__OscBKKeyboardTracking (_state.engine, value);
    }

    void Engine__OscBKKeyboardTracking (_Engine_1_State& _state, float value) noexcept
    {
        int32_t  v;

        _state.state.oscillatorB_Keyboard = ((value != static_cast<float> (int32_t {0})) ? 1.0f : 0.0f);
        _state.state.oscillatorB_Pitch = ((23.0f - (35.0f * _state.state.oscillatorB_Keyboard)) + static_cast<float> (static_cast<int32_t> ((2.0f - _state.state.oscillatorB_Keyboard) * (_state.state.oscillatorB_Freq + 0.4f))));
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     _state.voices[v].oscillatorB_Tune = ((((_state.state.oscillatorB_LOF + _state.state.oscillatorB_Pitch) + _state.state.oscillatorB_Fine) + _state.voices[v].oscillatorB_Rnd) + _state.state.tune);
     _state.voices[v].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[v].pitch) + _state.voices[v].oscillatorB_Tune);
     {
         ++v;
     }
 }
        }
    }

    void _sendEvent_WheelModulationLfoNoise (Pro54_State& _state, float value) noexcept
    {
        _Pro54__WheelModulationLfoNoise (_state._state, value);
    }

    void _Pro54__WheelModulationLfoNoise (_Pro54_State& _state, float value) noexcept
    {
        Engine__WheelModulationLfoNoise (_state.engine, value);
    }

    void Engine__WheelModulationLfoNoise (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.lfoNoiseMix = value;
    }

    void _sendEvent_WheelModulationFreqOscA (Pro54_State& _state, float value) noexcept
    {
        _Pro54__WheelModulationFreqOscA (_state._state, value);
    }

    void _Pro54__WheelModulationFreqOscA (_Pro54_State& _state, float value) noexcept
    {
        Engine__WheelModulationFreqOscA (_state.engine, value);
    }

    void Engine__WheelModulationFreqOscA (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.oscillatorA_FM_WM = ((value != static_cast<float> (int32_t {0})) ? 0.4f : 0.0f);
    }

    void _sendEvent_WheelModulationFreqOscB (Pro54_State& _state, float value) noexcept
    {
        _Pro54__WheelModulationFreqOscB (_state._state, value);
    }

    void _Pro54__WheelModulationFreqOscB (_Pro54_State& _state, float value) noexcept
    {
        Engine__WheelModulationFreqOscB (_state.engine, value);
    }

    void Engine__WheelModulationFreqOscB (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.oscillatorB_FM_WM = ((value != static_cast<float> (int32_t {0})) ? 0.4f : 0.0f);
    }

    void _sendEvent_WheelModulationPWA (Pro54_State& _state, float value) noexcept
    {
        _Pro54__WheelModulationPWA (_state._state, value);
    }

    void _Pro54__WheelModulationPWA (_Pro54_State& _state, float value) noexcept
    {
        Engine__WheelModulationPWA (_state.engine, value);
    }

    void Engine__WheelModulationPWA (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.oscillatorA_PW_WM = ((value != static_cast<float> (int32_t {0})) ? 1.0f : 0.0f);
    }

    void _sendEvent_WheelModulationPWB (Pro54_State& _state, float value) noexcept
    {
        _Pro54__WheelModulationPWB (_state._state, value);
    }

    void _Pro54__WheelModulationPWB (_Pro54_State& _state, float value) noexcept
    {
        Engine__WheelModulationPWB (_state.engine, value);
    }

    void Engine__WheelModulationPWB (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.oscillatorB_PW_WM = ((value != static_cast<float> (int32_t {0})) ? 1.0f : 0.0f);
    }

    void _sendEvent_WheelModulationFilter (Pro54_State& _state, float value) noexcept
    {
        _Pro54__WheelModulationFilter (_state._state, value);
    }

    void _Pro54__WheelModulationFilter (_Pro54_State& _state, float value) noexcept
    {
        Engine__WheelModulationFilter (_state.engine, value);
    }

    void Engine__WheelModulationFilter (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.filter_WM = ((value != static_cast<float> (int32_t {0})) ? 60.0f : 0.0f);
    }

    void _sendEvent_Glide (Pro54_State& _state, float value) noexcept
    {
        _Pro54__Glide (_state._state, value);
    }

    void _Pro54__Glide (_Pro54_State& _state, float value) noexcept
    {
        Engine__Glide (_state.engine, value);
    }

    void Engine__Glide (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.glide = Engine__exp_dB (_state, 80.0f - (72.0f * value));
        if (_state.state.unisonActive)
        {
 if (_state.state.glideFinal == _state.state.glideOut)
 {
     _state.state.glideInc = 0.0f;
 }
 else
 {
     if (_state.state.glideFinal > _state.state.glideOut)
     {
         _state.state.glideInc = ((_state.state.glide * _state.tau) * 1.0f);
     }
     else
     {
         _state.state.glideInc = (((- _state.state.glide) * _state.tau) * 1.0f);
     }
 }
        }
    }

    void _sendEvent_Unison (Pro54_State& _state, float value) noexcept
    {
        _Pro54__Unison (_state._state, value);
    }

    void _Pro54__Unison (_Pro54_State& _state, float value) noexcept
    {
        Engine__Unison (_state.engine, value);
    }

    void Engine__Unison (_Engine_1_State& _state, float value) noexcept
    {
        int32_t  v;
        int32_t  v_0;

        _state.state.unisonActive = (value != static_cast<float> (int32_t {0}));
        if (! _state.state.unisonActive)
        {
 _state.state.glideInc = 0.0f;
 {
     v = {};
     for (;;)
     {
         if (v >= int32_t {32})
         {
  break;
         }
         if (_state.voices[v].noteNumber >= static_cast<float> (int32_t {0}))
         {
  _state.voices[v].pitch = _state.voices[v].noteNumber;
  _state.voices[v].oscillatorA_F = Engine__pitchToFreq (_state, _state.voices[v].pitch + _state.voices[v].oscillatorA_Tune);
  _state.voices[v].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[v].pitch) + _state.voices[v].oscillatorB_Tune);
         }
         if (_state.voices[v].gate <= static_cast<float> (int32_t {0}))
         {
  _state.voices[v].envelopeA_Stage = int32_t {2};
  _state.voices[v].envelopeA_Fac = _state.state.envelopeA_R_FAC;
  _state.voices[v].envelopeA_Level = envelopeAOffset;
  _state.voices[v].envelopeA_SDif = (_state.voices[v].envelopeA_Out - _state.voices[v].envelopeA_Level);
  _state.voices[v].envelopeF_Stage = int32_t {2};
  _state.voices[v].envelopeF_Fac = _state.state.envelopeF_R_FAC;
  _state.voices[v].envelopeF_Level = 0.0f;
  _state.voices[v].envelopeF_SDif = (_state.voices[v].envelopeF_Out - _state.voices[v].envelopeF_Level);
         }
         {
  ++v;
         }
     }
 }
 _state.state.unisonGate = 0.0f;
        }
        else
        {
 _state.state.glideFinal = _state.state.unisonNote;
 if (_state.state.glideFinal == _state.state.glideOut)
 {
     _state.state.glideInc = 0.0f;
     {
         v_0 = {};
         for (;;)
         {
  if (v_0 >= int32_t {32})
  {
      break;
  }
  if (v_0 == _state.activeVoices)
  {
      break;
  }
  _state.voices[v_0].pitch = (_state.state.glideFinal + _state.voices[v_0].unisonRnd);
  _state.voices[v_0].oscillatorA_F = Engine__pitchToFreq (_state, _state.voices[v_0].pitch + _state.voices[v_0].oscillatorA_Tune);
  _state.voices[v_0].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[v_0].pitch) + _state.voices[v_0].oscillatorB_Tune);
  {
      ++v_0;
  }
         }
     }
 }
 else
 {
     if (_state.state.glideFinal > _state.state.glideOut)
     {
         _state.state.glideInc = ((_state.state.glide * _state.tau) * 1.0f);
     }
     else
     {
         _state.state.glideInc = (((- _state.state.glide) * _state.tau) * 1.0f);
     }
 }
 if (_state.state.droneActive)
 {
     Engine__sustainedNotesOff (_state);
     Engine__noteOn (_state, int32_t {60}, int32_t {64}, 0.0f);
     _state.sustainActive = true;
     Engine__noteOff (_state, int32_t {60}, int32_t {0});
 }
        }
    }

    void Engine__sustainedNotesOff (_Engine_1_State& _state) noexcept
    {
        int32_t  i;

        _state.sustainActive = false;
        {
 i = {};
 for (;;)
 {
     if (i >= int32_t {32})
     {
         break;
     }
     if (i == _state.activeVoices)
     {
         break;
     }
     if (_state.collVoiceSustain[i] ? (! _state.collVoiceHold[i]) : false)
     {
         _state.collVoiceSustain[i] = false;
         Engine__triggerNoteOff (_state, i, int32_t {0});
         Engine__releaseVoice (_state, i);
         _state.collVoiceNote[i] = (noteOffMarker - _state.collVoiceNote[i]);
     }
     {
         ++i;
     }
 }
        }
    }

    void _sendEvent_AmplifierAttack (Pro54_State& _state, float value) noexcept
    {
        _Pro54__AmplifierAttack (_state._state, value);
    }

    void _Pro54__AmplifierAttack (_Pro54_State& _state, float value) noexcept
    {
        Engine__AmplifierAttack (_state.engine, value);
    }

    void Engine__AmplifierAttack (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.envelopeA_Att = (_state.tau * Engine__timeToIncrement (_state, -5.0f + (90.7f * value)));
    }

    void _sendEvent_AmplifierDecay (Pro54_State& _state, float value) noexcept
    {
        _Pro54__AmplifierDecay (_state._state, value);
    }

    void _Pro54__AmplifierDecay (_Pro54_State& _state, float value) noexcept
    {
        Engine__AmplifierDecay (_state.engine, value);
    }

    void Engine__AmplifierDecay (_Engine_1_State& _state, float value) noexcept
    {
        float  factor;
        int32_t  v;

        value = (value * 0.01f);
        factor = Engine__timeToIncrement (_state, -3.0f + (85.0f * value)) * _state.tau;
        _state.state.envelopeA_D_FAC = ((static_cast<double> (factor) > 1.0) ? 0.0f : (1.0f - factor));
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     if (_state.voices[v].envelopeA_Stage == int32_t {1})
     {
         _state.voices[v].envelopeA_Fac = _state.state.envelopeA_D_FAC;
     }
     {
         ++v;
     }
 }
        }
    }

    void _sendEvent_AmplifierSustain (Pro54_State& _state, float value) noexcept
    {
        _Pro54__AmplifierSustain (_state._state, value);
    }

    void _Pro54__AmplifierSustain (_Pro54_State& _state, float value) noexcept
    {
        Engine__AmplifierSustain (_state.engine, value);
    }

    void Engine__AmplifierSustain (_Engine_1_State& _state, float value) noexcept
    {
        int32_t  v;

        value = (value * 0.01f);
        _state.state.envelopeA_Sus = (0.95f * value);
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     if (_state.voices[v].envelopeA_Stage == int32_t {1})
     {
         _state.voices[v].envelopeA_Level = (((_state.voices[v].envelopeA_Peak - envelopeAOffset) * _state.state.envelopeA_Sus) + envelopeAOffset);
         _state.voices[v].envelopeA_SDif = (_state.voices[v].envelopeA_Out - _state.voices[v].envelopeA_Level);
     }
     {
         ++v;
     }
 }
        }
    }

    void _sendEvent_AmplifierRelease (Pro54_State& _state, float value) noexcept
    {
        _Pro54__AmplifierRelease (_state._state, value);
    }

    void _Pro54__AmplifierRelease (_Pro54_State& _state, float value) noexcept
    {
        Engine__AmplifierRelease (_state.engine, value);
    }

    void Engine__AmplifierRelease (_Engine_1_State& _state, float value) noexcept
    {
        float  factor;
        int32_t  v;

        value = (value * 0.01f);
        _state.state.envelopeA_Rel = (-10.0f + (92.0f * value));
        factor = Engine__timeToIncrement (_state, _state.state.envelopeRelease * _state.state.envelopeA_Rel) * _state.tau;
        _state.state.envelopeA_R_FAC = ((static_cast<double> (factor) > 1.0) ? 0.0f : (1.0f - factor));
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     if (_state.voices[v].envelopeA_Stage == int32_t {2})
     {
         _state.voices[v].envelopeA_Fac = _state.state.envelopeA_R_FAC;
     }
     {
         ++v;
     }
 }
        }
    }

    void _sendEvent_Release (Pro54_State& _state, float value) noexcept
    {
        _Pro54__Release (_state._state, value);
    }

    void _Pro54__Release (_Pro54_State& _state, float value) noexcept
    {
        Engine__Release (_state.engine, value);
    }

    void Engine__Release (_Engine_1_State& _state, float value) noexcept
    {
        float  factor1;
        int32_t  v;
        float  factor2;
        int32_t  v_0;

        _state.state.envelopeRelease = ((value != static_cast<float> (int32_t {0})) ? 1.0f : 0.0f);
        factor1 = Engine__timeToIncrement (_state, _state.state.envelopeRelease * _state.state.envelopeA_Rel) * _state.tau;
        _state.state.envelopeA_R_FAC = ((static_cast<double> (factor1) > 1.0) ? 0.0f : (1.0f - factor1));
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     if (_state.voices[v].envelopeA_Stage == int32_t {2})
     {
         _state.voices[v].envelopeA_Fac = _state.state.envelopeA_R_FAC;
     }
     {
         ++v;
     }
 }
        }
        factor2 = Engine__timeToIncrement (_state, _state.state.envelopeRelease * _state.state.envelopeF_Rel) * _state.tau;
        _state.state.envelopeF_R_FAC = ((static_cast<double> (factor2) > 1.0) ? 0.0f : (1.0f - factor2));
        {
 v_0 = {};
 for (;;)
 {
     if (v_0 >= int32_t {32})
     {
         break;
     }
     if (_state.voices[v_0].envelopeF_Stage == int32_t {2})
     {
         _state.voices[v_0].envelopeF_Fac = _state.state.envelopeF_R_FAC;
     }
     {
         ++v_0;
     }
 }
        }
    }

    void _sendEvent_Velocity (Pro54_State& _state, float value) noexcept
    {
        _Pro54__Velocity (_state._state, value);
    }

    void _Pro54__Velocity (_Pro54_State& _state, float value) noexcept
    {
        Engine__Velocity (_state.engine, value);
    }

    void Engine__Velocity (_Engine_1_State& _state, float value) noexcept
    {
        if (value != static_cast<float> (int32_t {0}))
        {
 _state.state.velocityFilter = 0.55f;
 _state.state.velocityAmp = 0.8f;
        }
        else
        {
 _state.state.velocityFilter = 0.0f;
 _state.state.velocityAmp = 0.0f;
        }
    }

    void _sendEvent_Repeat (Pro54_State& _state, float value) noexcept
    {
        _Pro54__Repeat (_state._state, value);
    }

    void _Pro54__Repeat (_Pro54_State& _state, float value) noexcept
    {
        Engine__Repeat (_state.engine, value);
    }

    void Engine__Repeat (_Engine_1_State& _state, float value) noexcept
    {
        _state.state.repeatActive = (value != static_cast<float> (int32_t {0}));
    }

    void _sendEvent_Drone (Pro54_State& _state, float value) noexcept
    {
        _Pro54__Drone (_state._state, value);
    }

    void _Pro54__Drone (_Pro54_State& _state, float value) noexcept
    {
        Engine__Drone (_state.engine, value);
    }

    void Engine__Drone (_Engine_1_State& _state, float value) noexcept
    {
        bool  already_playing;
        int32_t  v;

        _state.state.droneActive = (static_cast<int32_t> (value) != int32_t {0});
        if (_state.state.droneActive)
        {
 already_playing = false;
 {
     v = {};
     for (;;)
     {
         if (v >= int32_t {32})
         {
  break;
         }
         if (v == _state.activeVoices)
         {
  break;
         }
         if (_state.collVoiceNote[v] > int32_t {0})
         {
  already_playing = true;
  break;
         }
         {
  ++v;
         }
     }
 }
 if (! already_playing)
 {
     Engine__noteOn (_state, int32_t {60}, int32_t {64}, 0.0f);
     _state.sustainActive = true;
     Engine__noteOff (_state, int32_t {60}, int32_t {0});
 }
 else
 {
     _state.sustainActive = true;
 }
        }
        else
        {
 Engine__sustainedNotesOff (_state);
        }
    }

    void _sendEvent_FilterHPF (Pro54_State& _state, float value) noexcept
    {
        _Pro54__FilterHPF (_state._state, value);
    }

    void _Pro54__FilterHPF (_Pro54_State& _state, float value) noexcept
    {
        Engine__FilterHPF (_state.engine, value);
    }

    void Engine__FilterHPF (_Engine_1_State& _state, float value) noexcept
    {
        float  Res;

        _state.state.filter_HPF = (value > static_cast<float> (int32_t {0}));
        Res = {};
        if (static_cast<double> (_state.state.filter_Res) < 0.25)
        {
 Res = (2.32f * _state.state.filter_Res);
        }
        else
        {
 if (static_cast<double> (_state.state.filter_Res) < 0.5)
 {
     Res = ((0.52f * _state.state.filter_Res) + 0.45f);
 }
 else
 {
     if (static_cast<double> (_state.state.filter_Res) < 0.75)
     {
         Res = ((0.92f * _state.state.filter_Res) + 0.25f);
     }
     else
     {
         Res = ((0.036f * _state.state.filter_Res) + 0.913f);
     }
 }
        }
        _state.state.filter_D = (2.0f - (2.0f * Res));
        if (_state.state.filter_HPF)
        {
 _state.state.filter_FMAX = (0.5f + ((0.0318f * Res) * (27.5989f + Res)));
        }
        else
        {
 _state.state.filter_FMAX = (0.7352f + ((0.293f * Res) * (1.3075f + Res)));
        }
        Res = (Res * 0.8f);
        _state.state.filterN_D = (2.0f - (2.0f * Res));
        if (_state.state.filter_HPF)
        {
 _state.state.filterN_FMAX = (0.5f + ((0.0318f * Res) * (27.5989f + Res)));
        }
        else
        {
 _state.state.filterN_FMAX = (0.7352f + ((0.293f * Res) * (1.3075f + Res)));
        }
        Engine__smoothValue (_state);
    }

    void _sendEvent_FilterInvertEnv (Pro54_State& _state, float value) noexcept
    {
        _Pro54__FilterInvertEnv (_state._state, value);
    }

    void _Pro54__FilterInvertEnv (_Pro54_State& _state, float value) noexcept
    {
        Engine__FilterInvertEnv (_state.engine, value);
    }

    void Engine__FilterInvertEnv (_Engine_1_State& _state, float value) noexcept
    {
        if (value != static_cast<float> (int32_t {0}))
        {
 _state.state.filterEnvelopeInv = -1.0f;
        }
        else
        {
 _state.state.filterEnvelopeInv = 1.0f;
        }
        if (_state.state.filterEnvelopeFinal > static_cast<float> (int32_t {0}))
        {
 _state.state.filterEnvelopeFinal = (_state.state.filterEnvelopeFinal * _state.state.filterEnvelopeInv);
        }
        else
        {
 _state.state.filterEnvelopeFinal = ((- _state.state.filterEnvelopeFinal) * _state.state.filterEnvelopeInv);
        }
        Engine__smoothValue (_state);
    }

    void _sendEvent_Analog (Pro54_State& _state, float value) noexcept
    {
        _Pro54__Analog (_state._state, value);
    }

    void _Pro54__Analog (_Pro54_State& _state, float value) noexcept
    {
        Engine__Analog (_state.engine, value);
    }

    void Engine__Analog (_Engine_1_State& _state, float value) noexcept
    {
        float  _temp;
        float  tune;
        int32_t  seed;
        int32_t  v;
        int32_t  Feedback;

        value = (value * 0.01f);
        if (value > static_cast<float> (int32_t {0}))
        {
 _temp = (Engine__exp_E (_state, 5.0f * value) * 0.19205f);
        }
        else
        {
 _temp = 0.0f;
        }
        tune = _temp;
        seed = int32_t {0x499602d2};
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     Feedback = ((seed ^ (seed >> int32_t {5})) ^ (seed >> int32_t {13})) << int32_t {31};
     seed = (seed >> int32_t {1});
     seed = (seed | Feedback);
     _state.voices[v].oscillatorA_Rnd = ((0.01f * tune) * (-1.0f + (0.000030518f * static_cast<float> (seed & int32_t {65535}))));
     _state.voices[v].oscillatorA_Tune = ((_state.state.oscillatorA_Freq + _state.voices[v].oscillatorA_Rnd) + _state.state.tune);
     Feedback = (((seed ^ (seed >> int32_t {5})) ^ (seed >> int32_t {13})) << int32_t {31});
     seed = (seed >> int32_t {1});
     seed = (seed | Feedback);
     _state.voices[v].oscillatorB_Rnd = ((0.01f * tune) * (-1.0f + (0.000030518f * static_cast<float> (seed & int32_t {65535}))));
     _state.voices[v].oscillatorB_Tune = ((((_state.state.oscillatorB_LOF + _state.state.oscillatorB_Pitch) + _state.state.oscillatorB_Fine) + _state.voices[v].oscillatorB_Rnd) + _state.state.tune);
     Feedback = (((seed ^ (seed >> int32_t {5})) ^ (seed >> int32_t {13})) << int32_t {31});
     seed = (seed >> int32_t {1});
     seed = (seed | Feedback);
     _state.voices[v].filter_RND = ((0.5f * tune) * (-1.0f + (0.000030518f * static_cast<float> (seed & int32_t {65535}))));
     Engine__smoothValue (_state);
     Feedback = (((seed ^ (seed >> int32_t {5})) ^ (seed >> int32_t {13})) << int32_t {31});
     seed = (seed >> int32_t {1});
     seed = (seed | Feedback);
     _state.voices[v].polymodEnvRnd = (1.0f + ((0.1f * tune) * (-1.0f + (0.000030518f * static_cast<float> (seed & int32_t {65535})))));
     Feedback = (((seed ^ (seed >> int32_t {5})) ^ (seed >> int32_t {13})) << int32_t {31});
     seed = (seed >> int32_t {1});
     seed = (seed | Feedback);
     if (tune != static_cast<float> (int32_t {0}))
     {
         _state.voices[v].unisonRnd = ((0.035f * tune) * (-1.0f + (0.000030518f * static_cast<float> (seed & int32_t {65535}))));
     }
     else
     {
         _state.voices[v].unisonRnd = ((0.07f / static_cast<float> (_state.activeVoices)) * static_cast<float> (static_cast<bool> (v & int32_t {1}) ? ((v + int32_t {1}) >> int32_t {1}) : (- (v >> int32_t {1}))));
     }
     Engine__updatePitch (_state);
     {
         ++v;
     }
 }
        }
    }

    void Engine__updatePitch (_Engine_1_State& _state) noexcept
    {
        int32_t  v;
        int32_t  v_0;

        if (_state.state.unisonActive)
        {
 _state.state.glideFinal = _state.state.unisonNote;
 if (_state.state.glideFinal == _state.state.glideOut)
 {
     _state.state.glideInc = 0.0f;
     {
         v = {};
         for (;;)
         {
  if (v >= int32_t {32})
  {
      break;
  }
  if (v == _state.activeVoices)
  {
      break;
  }
  _state.voices[v].pitch = (_state.state.glideFinal + _state.voices[v].unisonRnd);
  _state.voices[v].oscillatorA_F = Engine__pitchToFreq (_state, _state.voices[v].pitch + _state.voices[v].oscillatorA_Tune);
  _state.voices[v].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[v].pitch) + _state.voices[v].oscillatorB_Tune);
  {
      ++v;
  }
         }
     }
 }
 else
 {
     if (_state.state.glideFinal > _state.state.glideOut)
     {
         _state.state.glideInc = ((_state.state.glide * _state.tau) * 1.0f);
     }
     else
     {
         _state.state.glideInc = (((- _state.state.glide) * _state.tau) * 1.0f);
     }
 }
        }
        else
        {
 {
     v_0 = {};
     for (;;)
     {
         if (v_0 >= int32_t {32})
         {
  break;
         }
         if (_state.voices[v_0].noteNumber >= static_cast<float> (int32_t {0}))
         {
  _state.voices[v_0].pitch = _state.voices[v_0].noteNumber;
  _state.voices[v_0].oscillatorA_F = Engine__pitchToFreq (_state, _state.voices[v_0].pitch + _state.voices[v_0].oscillatorA_Tune);
  _state.voices[v_0].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[v_0].pitch) + _state.voices[v_0].oscillatorB_Tune);
         }
         _state.voices[v_0].oscillatorA_F = Engine__pitchToFreq (_state, _state.voices[v_0].pitch + _state.voices[v_0].oscillatorA_Tune);
         _state.voices[v_0].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[v_0].pitch) + _state.voices[v_0].oscillatorB_Tune);
         {
  ++v_0;
         }
     }
 }
        }
    }

    void _sendEvent_MasterTune (Pro54_State& _state, float value) noexcept
    {
        _Pro54__MasterTune (_state._state, value);
    }

    void _Pro54__MasterTune (_Pro54_State& _state, float value) noexcept
    {
        Engine__MasterTune (_state.engine, value);
    }

    void Engine__MasterTune (_Engine_1_State& _state, float value) noexcept
    {
        int32_t  v;

        value = (value * 0.01f);
        _state.state.masterTune = (-0.7f + (1.4f * value));
        _state.state.tune = (_state.state.masterTune + _state.state.pitchBend);
        {
 v = {};
 for (;;)
 {
     if (v >= int32_t {32})
     {
         break;
     }
     _state.voices[v].oscillatorA_Tune = ((_state.state.oscillatorA_Freq + _state.voices[v].oscillatorA_Rnd) + _state.state.tune);
     _state.voices[v].oscillatorA_F = Engine__pitchToFreq (_state, _state.voices[v].pitch + _state.voices[v].oscillatorA_Tune);
     _state.voices[v].oscillatorB_Tune = ((((_state.state.oscillatorB_LOF + _state.state.oscillatorB_Pitch) + _state.state.oscillatorB_Fine) + _state.voices[v].oscillatorB_Rnd) + _state.state.tune);
     _state.voices[v].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[v].pitch) + _state.voices[v].oscillatorB_Tune);
     {
         ++v;
     }
 }
        }
    }

    void _sendEvent_Volume (Pro54_State& _state, float value) noexcept
    {
        _Pro54__Volume (_state._state, value);
    }

    void _Pro54__Volume (_Pro54_State& _state, float value) noexcept
    {
        Engine__Volume (_state.engine, value);
    }

    void Engine__Volume (_Engine_1_State& _state, float value) noexcept
    {
        value = (value * 0.01f);
        _state.state.volumeFinal = (masterVolume * value);
        Engine__smoother (_state);
    }

    void _sendEvent_ModWheel (Pro54_State& _state, float value) noexcept
    {
        _Pro54__ModWheel (_state._state, value);
    }

    void _Pro54__ModWheel (_Pro54_State& _state, float value) noexcept
    {
        Engine__ModWheel (_state.engine, value);
    }

    void Engine__ModWheel (_Engine_1_State& _state, float value) noexcept
    {
        Engine__setModWheel (_state, value * 0.01f);
    }

    void _sendEvent_PitchBend (Pro54_State& _state, float value) noexcept
    {
        _Pro54__PitchBend (_state._state, value);
    }

    void _Pro54__PitchBend (_Pro54_State& _state, float value) noexcept
    {
        Engine__PitchBend (_state.engine, value);
    }

    void Engine__PitchBend (_Engine_1_State& _state, float value) noexcept
    {
        Engine__setPitchBend (_state, value * 0.01f);
    }

    void _sendEvent_FilterVersion (Pro54_State& _state, float value) noexcept
    {
        _Pro54__FilterVersion (_state._state, value);
    }

    void _Pro54__FilterVersion (_Pro54_State& _state, float value) noexcept
    {
        Engine__FilterVersion (_state.engine, value);
    }

    void Engine__FilterVersion (_Engine_1_State& _state, float n) noexcept
    {
        _state.filterVersion = ((n > 0.6f) ? int32_t {2} : ((n < 0.3f) ? int32_t {0} : int32_t {1}));
    }

    void _sendEvent_ActiveVoices (Pro54_State& _state, float value) noexcept
    {
        _Pro54__ActiveVoices (_state._state, value);
    }

    void _Pro54__ActiveVoices (_Pro54_State& _state, float value) noexcept
    {
        Engine__ActiveVoices (_state.engine, value);
    }

    void Engine__ActiveVoices (_Engine_1_State& _state, float value) noexcept
    {
        int32_t  v;

        v = std__intrinsics___wrap_33 (static_cast<int32_t> (value));
        if (_state.activeVoices != v)
        {
 _state.activeVoices = v;
 Engine__allSoundOff (_state);
        }
    }

    int32_t std__intrinsics___wrap_33 (int32_t n) noexcept
    {
        int32_t  x;

        x = intrinsics::modulo (n, int32_t {33});
        return (x < int32_t {0}) ? (x + int32_t {33}) : x;
    }

    void Engine__allSoundOff (_Engine_1_State& _state) noexcept
    {
        int32_t  i;

        {
 i = {};
 for (;;)
 {
     if (i >= int32_t {32})
     {
         break;
     }
     _state.voices[i].gate = 0.0f;
     _state.voices[i].noteNumber = 255.0f;
     _state.voices[i].oscillatorA_Phase = (intrinsics::fmod (static_cast<float> (i) * 1.97f, 2.0f) - static_cast<float> (int32_t {1}));
     _state.voices[i].oscillatorB_Phase = (intrinsics::fmod (static_cast<float> (i) * 1.87f, 2.0f) - static_cast<float> (int32_t {1}));
     _state.voices[i].oscillatorA_Saw_AA2 = 0.0f;
     _state.voices[i].oscillatorA_Pulse_AA2 = 0.0f;
     _state.voices[i].oscillatorB_Saw_AA2 = 0.0f;
     _state.voices[i].oscillatorB_Pulse_AA2 = 0.0f;
     _state.voices[i].filter_BPF = 0.0f;
     _state.voices[i].filter_LPF = 0.0f;
     _state.voices[i].filterN_BPF = 0.0f;
     _state.voices[i].filterN_LPF = 0.0f;
     _state.voices[i].envelopeA_Out = 0.0f;
     _state.voices[i].envelopeA_SDif = 0.0f;
     _state.voices[i].envelopeA_Level = 0.0f;
     _state.voices[i].envelopeF_Out = 0.0f;
     _state.voices[i].isActive = false;
     _state.voices[i].filter_Event = (_state.state.filter_Event + _state.voices[i].filter_RND);
     {
         ++i;
     }
 }
        }
        _state.state.unisonNote = 36.0f;
        _state.delayBuffer = __constant__0;
        Engine__setPitchBend (_state, 0.5f);
        Engine__initVoiceQueue (_state);
    }

    float std__intrinsics__fmod (float x, float y) noexcept
    {
        {
 return x - (y * static_cast<float> (static_cast<int64_t> (x / y)));
        }
    }

    void Engine__initVoiceQueue (_Engine_1_State& _state) noexcept
    {
        int32_t  i;
        int32_t  i_0;

        {
 i = {};
 for (;;)
 {
     if (i >= int32_t {32})
     {
         break;
     }
     _state.collVoiceSustain[i] = false;
     _state.collVoiceHold[i] = false;
     Engine__triggerNoteOff (_state, i, int32_t {0});
     _state.collVoiceNote[i] = noteOffMarker;
     {
         ++i;
     }
 }
        }
        {
 i_0 = int32_t {0};
 for (;;)
 {
     if  (! (i_0 < numVoices))
     {
         break;
     }
     _state.collVoicePrev[i_0 & int32_t {31}] = (i_0 - int32_t {1});
     _state.collVoiceNext[i_0 & int32_t {31}] = (i_0 + int32_t {1});
     {
         ++i_0;
     }
 }
        }
        _state.collVoicePrev[int32_t {0}] = (_state.activeVoices - int32_t {1});
        _state.collVoiceNext[(_state.activeVoices - int32_t {1}) & int32_t {31}] = int32_t {0};
        _state.youngestOffVoice = (_state.activeVoices - int32_t {1});
        _state.oldestVoice = int32_t {0};
        _state.sustainActive = false;
        if (_state.state.droneActive)
        {
 Engine__noteOn (_state, int32_t {60}, int32_t {64}, 0.0f);
 _state.sustainActive = true;
 Engine__noteOff (_state, int32_t {60}, int32_t {0});
        }
    }

    void _sendEvent_TestTone (Pro54_State& _state, float value) noexcept
    {
        _Pro54__TestTone (_state._state, value);
    }

    void _Pro54__TestTone (_Pro54_State& _state, float value) noexcept
    {
        Engine__TestTone (_state.engine, value);
    }

    void Engine__TestTone (_Engine_1_State& _state, float f) noexcept
    {
        _state.testToneActive = (f != static_cast<float> (int32_t {0}));
    }

    void _sendEvent_midiIn (Pro54_State& _state, std_midi_Message value) noexcept
    {
        _Pro54__midiIn (_state._state, value);
    }

    void _Pro54__midiIn (_Pro54_State& _state, std_midi_Message m) noexcept
    {
        std__midi__MPEConverter__parseMIDI (_state._implicit_std__midi__MPEConverter, m);
    }

    void std__midi__MPEConverter__parseMIDI (std_midi_MPEConverter_1_State& _state, std_midi_Message message) noexcept
    {
        std_notes_NoteOn  _temp;
        std_notes_NoteOn  _temp_0;
        std_notes_NoteOff  _temp_1;
        std_notes_NoteOff  _temp_2;
        std_notes_PitchBend  _temp_3;
        std_notes_PitchBend  _temp_4;
        std_notes_Pressure  _temp_5;
        std_notes_Pressure  _temp_6;
        std_notes_Slide  _temp_7;
        std_notes_Slide  _temp_8;
        std_notes_Control  _temp_9;
        std_notes_Control  _temp_10;

        if (std__midi__isNoteOn (message))
        {
 _temp.channel = std__midi__getChannel0to15 (message);
 _temp.pitch = std__midi__getPitch (message);
 _temp.velocity = std__midi__getFloatVelocity (message);
 _temp_0 = _temp;
 std__midi__MPEConverter___writeEvent_eventOut (_state, _temp_0);
        }
        else
        {
 if (std__midi__isNoteOff (message))
 {
     _temp_1.channel = std__midi__getChannel0to15 (message);
     _temp_1.pitch = std__midi__getPitch (message);
     _temp_1.velocity = std__midi__getFloatVelocity (message);
     _temp_2 = _temp_1;
     std__midi__MPEConverter___writeEvent_eventOut_0 (_state, _temp_2);
 }
 else
 {
     if (std__midi__isPitchWheel (message))
     {
         _temp_3.channel = std__midi__getChannel0to15 (message);
         _temp_3.bendSemitones = (0.005859375f * static_cast<float> (std__midi__get14BitValue (message) - int32_t {8192}));
         _temp_4 = _temp_3;
         std__midi__MPEConverter___writeEvent_eventOut_1 (_state, _temp_4);
     }
     else
     {
         if (std__midi__isChannelPressure (message))
         {
  _temp_5.channel = std__midi__getChannel0to15 (message);
  _temp_5.pressure = std__midi__getFloatChannelPressureValue (message);
  _temp_6 = _temp_5;
  std__midi__MPEConverter___writeEvent_eventOut_2 (_state, _temp_6);
         }
         else
         {
  if (std__midi__isController (message))
  {
      if (std__midi__getControllerNumber (message) == slideController)
      {
          _temp_7.channel = std__midi__getChannel0to15 (message);
          _temp_7.slide = std__midi__getFloatControllerValue (message);
          _temp_8 = _temp_7;
          std__midi__MPEConverter___writeEvent_eventOut_3 (_state, _temp_8);
      }
      else
      {
          _temp_9.channel = std__midi__getChannel0to15 (message);
          _temp_9.control = std__midi__getControllerNumber (message);
          _temp_9.value = std__midi__getFloatControllerValue (message);
          _temp_10 = _temp_9;
          std__midi__MPEConverter___writeEvent_eventOut_4 (_state, _temp_10);
      }
  }
         }
     }
 }
        }
    }

    bool std__midi__isNoteOn (const std_midi_Message& this_) noexcept
    {
        return ((this_.message & int32_t {0xf00000}) == int32_t {0x900000}) ? ((this_.message & int32_t {255}) != int32_t {0}) : false;
    }

    void std__midi__MPEConverter___writeEvent_eventOut (std_midi_MPEConverter_1_State& _state, const std_notes_NoteOn& value) noexcept
    {
        _Pro54___forwardEvent (state_upcast_struct_Pro54_State_struc_fGKm8b(_state), value);
    }

    void _Pro54___forwardEvent (_Pro54_State& _state, std_notes_NoteOn value) noexcept
    {
        Engine__eventIn (_state.engine, value);
    }

    int32_t std__midi__getChannel0to15 (const std_midi_Message& this_) noexcept
    {
        return (this_.message >> int32_t {16}) & int32_t {15};
    }

    float std__midi__getPitch (const std_midi_Message& this_) noexcept
    {
        return static_cast<float> (std__midi__getNoteNumber (this_));
    }

    int32_t std__midi__getNoteNumber (const std_midi_Message& this_) noexcept
    {
        return (this_.message >> int32_t {8}) & int32_t {127};
    }

    float std__midi__getFloatVelocity (const std_midi_Message& this_) noexcept
    {
        return static_cast<float> (this_.message & int32_t {127}) * 0.007874016f;
    }

    bool std__midi__isNoteOff (const std_midi_Message& this_) noexcept
    {
        return ((this_.message & int32_t {0xf00000}) == int32_t {0x800000}) ? true : ((this_.message & int32_t {0xf000ff}) == int32_t {0x900000});
    }

    void std__midi__MPEConverter___writeEvent_eventOut_0 (std_midi_MPEConverter_1_State& _state, const std_notes_NoteOff& value) noexcept
    {
        _Pro54___forwardEvent_2 (state_upcast_struct_Pro54_State_struc_fGKm8b(_state), value);
    }

    void _Pro54___forwardEvent_2 (_Pro54_State& _state, std_notes_NoteOff value) noexcept
    {
        Engine__eventIn_0 (_state.engine, value);
    }

    bool std__midi__isPitchWheel (const std_midi_Message& this_) noexcept
    {
        return (this_.message & int32_t {0xf00000}) == int32_t {0xe00000};
    }

    void std__midi__MPEConverter___writeEvent_eventOut_1 (std_midi_MPEConverter_1_State& _state, const std_notes_PitchBend& value) noexcept
    {
        _Pro54___forwardEvent_3 (state_upcast_struct_Pro54_State_struc_fGKm8b(_state), value);
    }

    void _Pro54___forwardEvent_3 (_Pro54_State& _state, std_notes_PitchBend value) noexcept
    {
        Engine__eventIn_1 (_state.engine, value);
    }

    int32_t std__midi__get14BitValue (const std_midi_Message& this_) noexcept
    {
        return ((this_.message >> int32_t {8}) & int32_t {127}) | ((this_.message & int32_t {127}) << int32_t {7});
    }

    bool std__midi__isChannelPressure (const std_midi_Message& this_) noexcept
    {
        return (this_.message & int32_t {0xf00000}) == int32_t {0xd00000};
    }

    void std__midi__MPEConverter___writeEvent_eventOut_2 (std_midi_MPEConverter_1_State& _state, const std_notes_Pressure& value) noexcept
    {
    }

    float std__midi__getFloatChannelPressureValue (const std_midi_Message& this_) noexcept
    {
        return static_cast<float> ((this_.message >> int32_t {8}) & int32_t {127}) * 0.007874016f;
    }

    bool std__midi__isController (const std_midi_Message& this_) noexcept
    {
        return (this_.message & int32_t {0xf00000}) == int32_t {0xb00000};
    }

    int32_t std__midi__getControllerNumber (const std_midi_Message& this_) noexcept
    {
        return (this_.message >> int32_t {8}) & int32_t {127};
    }

    void std__midi__MPEConverter___writeEvent_eventOut_3 (std_midi_MPEConverter_1_State& _state, const std_notes_Slide& value) noexcept
    {
    }

    float std__midi__getFloatControllerValue (const std_midi_Message& this_) noexcept
    {
        return static_cast<float> (this_.message & int32_t {127}) * 0.007874016f;
    }

    void std__midi__MPEConverter___writeEvent_eventOut_4 (std_midi_MPEConverter_1_State& _state, const std_notes_Control& value) noexcept
    {
        _Pro54___forwardEvent_4 (state_upcast_struct_Pro54_State_struc_fGKm8b(_state), value);
    }

    void _Pro54___forwardEvent_4 (_Pro54_State& _state, std_notes_Control value) noexcept
    {
        Engine__eventIn_2 (_state.engine, value);
    }

    void _initialise (Pro54_State& _state, int32_t& processorID, int32_t sessionID, double frequency) noexcept
    {
        _Pro54___initialise (_state._state, processorID, sessionID, frequency);
    }

    void _Pro54___initialise (_Pro54_State& _state, int32_t& processorID, int32_t sessionID, double frequency) noexcept
    {
        _sessionID = sessionID;
        _frequency = frequency;
        Engine___initialise (_state.engine, processorID, sessionID, frequency);
        _initialise_0 (_state._implicit_std__midi__MPEConverter, processorID, sessionID, frequency);
    }

    void Engine___initialise (_Engine_1_State& _state, int32_t& processorID, int32_t sessionID, double frequency) noexcept
    {
        _sessionID = sessionID;
        _frequency = frequency;
        _state.tauFilter = static_cast<float> (6.283 / (1.0 * _frequency));
        _state.tau = static_cast<float> (1.0 / (1.0 * _frequency));
        _state.activeVoices = int32_t {5};
        _state.youngestOffVoice = int32_t {-1};
        _state.oldestVoice = int32_t {-1};
        _state.piOverSampleRate = static_cast<float> (3.141592653589793 / (1.0 * _frequency));
        _state.noiseScale = static_cast<float> (intrinsics::sqrt ((1.0 * _frequency) / static_cast<double> (int32_t {44100})) * 4.6566129e-10);
        Engine__init (_state);
    }

    double std__intrinsics__sqrt (double n) noexcept
    {
        {
 return 0.0;
        }
    }

    void Engine__init (_Engine_1_State& _state) noexcept
    {
        int32_t  i;

        Engine__initExponentLUT (_state);
        Engine__updateAllTauDependendSignals (_state);
        _state.state.A440Phase = 0.0f;
        _state.state.smootherCount = int32_t {0};
        _state.state.volumeSmooth = 0.0f;
        _state.state.delayDrySmooth = 0.0f;
        _state.state.delayWetSmooth = 0.0f;
        _state.state.delayFeedbackSmooth = 0.0f;
        _state.state.filterEnvelopeInv = 1.0f;
        _state.state.glideOut = 36.0f;
        _state.state.controlCount = 100.0f;
        _state.state.noiseMem = int64_t {1L};
        {
 i = {};
 for (;;)
 {
     if (i >= int32_t {32})
     {
         break;
     }
     _state.collVoiceSustain[i] = false;
     _state.collVoiceHold[i] = false;
     _state.collVoiceNote[i] = noteOffMarker;
     {
         ++i;
     }
 }
        }
        Engine__allSoundOff (_state);
    }

    void Engine__initExponentLUT (_Engine_1_State& _state) noexcept
    {
        int32_t  i;
        float  value;

        _state.exponentLUT[int32_t {0}] = 9.536743e-7f;
        {
 i = int32_t {1};
 for (;;)
 {
     if  (! (i < int32_t {2401}))
     {
         break;
     }
     value = intrinsics::pow (2.0f, (static_cast<float> (i) - 1200.0f) / 60.0f);
     _state.exponentLUT[std__intrinsics___wrap_2401 (i)] = value;
     _state.exponentLUTSlope[std__intrinsics___wrap_2400 (i - int32_t {1})] = (value - _state.exponentLUT[std__intrinsics___wrap_2401 (i - int32_t {1})]);
     {
         ++i;
     }
 }
        }
    }

    float std__intrinsics__pow (float a, float b) noexcept
    {
        {
 return 0.0f;
        }
    }

    void Engine__updateAllTauDependendSignals (_Engine_1_State& _state) noexcept
    {
        _state.state.delayDepth = (_state.state.delayDepthKnob * static_cast<float> (1.0 * _frequency));
        Engine__computeDelayTimes (_state);
        _state.state.A440FilterFreq = (Engine__pitchToFreq (_state, 55.0f) * _state.tauFilter);
        _state.state.noiseFilterFreq = (Engine__pitchToFreq (_state, 50.0f) * _state.tauFilter);
        _state.state.filter1HPF = (Engine__pitchToFreq (_state, -40.0f) * _state.tauFilter);
        _state.state.A440Freq = (440.0f * _state.tau);
    }

    void _initialise_0 (std_midi_MPEConverter_1_State& _state, int32_t& processorID, int32_t sessionID, double frequency) noexcept
    {
    }

    void _advance (Pro54_State& _state, Pro54_IO& _io, int32_t _frames) noexcept
    {
        _Pro54_IO  ioCopy;

        for (;;)
        {
 if (_state._currentFrame == _frames)
 {
     break;
 }
 ioCopy = _Pro54_IO {};
 ioCopy.externalIn = _io.externalIn[_state._currentFrame];
 main (_state._state, ioCopy);
 _io.out[_state._currentFrame] = ioCopy.out;
 ++_state._currentFrame;
        }
        _state._currentFrame = int32_t {0};
    }

    void main (_Pro54_State& _state, _Pro54_IO& _io) noexcept
    {
        _Engine_1_IO  engine_io;
        std_midi_MPEConverter_1_IO  _implicit_std__midi__MPEConverter_io;

        engine_io = _Engine_1_IO {};
        _implicit_std__midi__MPEConverter_io = std_midi_MPEConverter_1_IO {};
        {
        }
        main_0 (_state._implicit_std__midi__MPEConverter, _implicit_std__midi__MPEConverter_io);
        {
 engine_io.externalIn = (engine_io.externalIn + _io.externalIn);
        }
        Engine__main (_state.engine, engine_io);
        {
 _io.out = (_io.out + engine_io.out);
        }
    }

    void main_0 (std_midi_MPEConverter_1_State& _state, std_midi_MPEConverter_1_IO& _io) noexcept
    {
    }

    void Engine__main (_Engine_1_State& _state, _Engine_1_IO& _io) noexcept
    {
        float  LFO_Pulse;
        float  LFO_Saw;
        float  LFO_Tri;
        float  Noise_White;
        float  Noise_Filtered;
        float  PolyMod;
        float  PulseWidthA;
        float  PulseWidthB;
        float  WheelMod2OscAFm;
        float  WheelMod2OscBFm;
        float  WheelMod2Filt;
        float  OscB_All;
        float  OscB_Pulse;
        float  OscB_Saw;
        float  OscB_Tri;
        float  OscB_PulseTri;
        float  OscA_Pulse;
        float  OscA_Saw;
        float  EQ_Out;
        float  Mixer;
        bool  oscillatorSyncNow;
        float  Osc_Sync_x;
        float  Inc;
        float  Diff;
        float  diffInc;
        int32_t  v;
        float  peakA;
        float  peakF;
        float  Diff_0;
        int32_t  v_0;
        int64_t  Wort;
        int64_t  Feedback;
        float  Hpf;
        float  In1;
        float  In2;
        float  WheelMod;
        int32_t  v_1;
        int32_t  v_2;
        int32_t  v_3;
        float  final_;
        float  tri;
        float  final__0;
        float  inputSignal;
        float  voiceOutput;
        int32_t  v_4;
        float  final__1;
        bool  useNewOsc;
        float  f;
        float  ph;
        float  newph;
        float  level;
        float  cposMain;
        float  sgnf;
        float  pwmain;
        float  cpos;
        float  cpos_0;
        float  cpos_1;
        float  out;
        float  f_0;
        float  ph_0;
        float  d;
        float  f_rcp;
        float  x;
        float  x_1;
        float  aa_dn_1;
        float  y_saw;
        float  aa_dn_2;
        float  ph_pwm;
        float  ph2;
        float  ph2_sign;
        float  ph3;
        float  pulse_aa_2;
        float  ph3_abs;
        float  x3;
        float  x3_1;
        float  aa_up_1;
        float  aa_up_2;
        float  y_pulse;
        float  y_pulse_0;
        float  aa_top;
        float  aa_btm;
        float  aa_top_0;
        float  y_saw_0;
        float  ph_pwm_0;
        float  ph2_0;
        float  ph2_sign_0;
        float  ph3_0;
        float  pulse_aa_2_0;
        float  ph3_abs_0;
        float  x3_0;
        float  x3_1_0;
        float  aa_up_1_0;
        float  aa_up_2_0;
        float  y_pulse_1;
        float  y_pulse_2;
        float  ph_sign;
        float  ph_abs;
        float  x5;
        float  aa_btm_0;
        float  f_1;
        float  ph_1;
        float  x_snc;
        float  x_snc_1;
        float  d_snc;
        float  snc_ph;
        float  ph_adj;
        float  ph_abs_0;
        float  d_0;
        float  f_rcp_0;
        float  x_0;
        float  x_1_0;
        float  ph2_1;
        float  ph_snc_change;
        float  snc_aa_amp;
        float  aa_dn_1_0;
        float  aa_snc_1;
        float  aa_snc_1_saw;
        float  aa_dn_2_0;
        float  aa_snc_2;
        float  aa_snc_2_saw;
        float  y_saw_1;
        float  ph_pwm_1;
        float  ph3_1;
        float  ph4;
        float  aa_up_snc_1;
        float  aa_up_snc_2;
        float  x4;
        float  x4_1;
        float  aa_snc_1_pulse;
        float  aa_snc_2_pulse;
        float  ph2_sign_1;
        float  pulse_aa_2_1;
        float  ph3_abs_1;
        float  x3_2;
        float  x3_1_1;
        float  aa_up_1_1;
        float  aa_up_2_1;
        float  y_pulse_3;
        float  y_pulse_4;
        float  ph2_2;
        float  ph_snc_change_0;
        float  snc_aa_amp_0;
        float  aa_snc_1_0;
        float  aa_snc_1_saw_0;
        float  aa_snc_2_0;
        float  aa_snc_2_saw_0;
        float  y_saw_2;
        float  ph_pwm_2;
        float  ph3_2;
        float  ph4_0;
        float  aa_up_snc_1_0;
        float  aa_up_snc_2_0;
        float  x4_0;
        float  x4_1_0;
        float  aa_snc_1_pulse_0;
        float  aa_snc_2_pulse_0;
        float  ph2_sign_2;
        float  pulse_aa_2_2;
        float  ph3_abs_2;
        float  x3_3;
        float  x3_1_2;
        float  aa_up_1_2;
        float  aa_up_2_2;
        float  y_pulse_5;
        float  y_pulse_6;
        float  d_1;
        float  f_rcp_1;
        float  x_2;
        float  x_1_1;
        float  aa_dn_1_1;
        float  aa_dn_2_1;
        float  y_saw_3;
        float  ph_pwm_3;
        float  ph2_3;
        float  ph2_sign_3;
        float  ph3_3;
        float  pulse_aa_2_3;
        float  ph3_abs_3;
        float  x3_4;
        float  x3_1_3;
        float  aa_up_1_3;
        float  aa_up_2_3;
        float  y_pulse_7;
        float  y_pulse_8;
        float  y_saw_4;
        float  ph_pwm_4;
        float  ph2_4;
        float  ph2_sign_4;
        float  ph3_4;
        float  pulse_aa_2_4;
        float  ph3_abs_4;
        float  x3_5;
        float  x3_1_4;
        float  aa_up_1_4;
        float  aa_up_2_4;
        float  y_pulse_9;
        float  y_pulse_10;
        float  EQ_In;
        float  satIn;
        float  FM;
        float  FN;
        float  F;
        float  In;
        float  hpf;
        float  notch;
        float  notch_0;
        float  filter1_Hpf;
        bool  bAA;
        bool  bBPF;
        float  FM_0;
        float  F_0;
        float  g;
        float  norm;
        float  gnorm;
        float  gnorm2;
        float  GF;
        float  G;
        float  scale;
        float  x_3;
        Array<float, 5>  s;
        float  x_;
        float  g2;
        float  g2norm;
        float  S;
        float  u;
        float  S_0;
        float  u_0;
        float  dryOut;
        float  delayL;
        float  delayR;
        float  Hpf_0;
        float  prec1;
        int32_t  trunc1;
        float  lo1;
        float  hi1;
        float  delay1;
        float  prec2;
        int32_t  trunc2;
        float  lo2;
        float  hi2;
        float  delay2;
        float  prec3;
        int32_t  trunc3;
        float  lo3;
        float  hi3;
        float  delay3;
        float  prec4;
        int32_t  trunc4;
        float  lo4;
        float  hi4;
        float  delay4;
        float  Inc_0;
        float  A440_Pulse;
        float  diff;
        float  diffInc_0;
        float  diff_0;
        float  hpf_0;
        Vector<float, 2>  _temp;

        for (;;)
        {
 LFO_Pulse = {};
 LFO_Saw = {};
 LFO_Tri = {};
 Noise_White = {};
 Noise_Filtered = {};
 PolyMod = {};
 PulseWidthA = {};
 PulseWidthB = {};
 WheelMod2OscAFm = {};
 WheelMod2OscBFm = {};
 WheelMod2Filt = {};
 OscB_All = {};
 OscB_Pulse = {};
 OscB_Saw = {};
 OscB_Tri = {};
 OscB_PulseTri = {};
 OscA_Pulse = {};
 OscA_Saw = {};
 EQ_Out = {};
 Mixer = {};
 oscillatorSyncNow = false;
 Osc_Sync_x = {};
 {
     Inc = _state.state.lfoFreq * _state.tau;
     _state.state.lfoPhase = (_state.state.lfoPhase + Inc);
     if (_state.state.lfoPulseSign)
     {
         Diff = 1.0f - _state.state.lfoPhase;
         if (Diff > (0.5f * Inc))
         {
  LFO_Pulse = _state.state.lfoPulseA;
  LFO_Saw = (_state.state.lfoSawA * _state.state.lfoPhase);
  LFO_Tri = (_state.state.lfoTriangleA * ((2.0f * _state.state.lfoPhase) - 1.5f));
         }
         else
         {
  diffInc = 0.5f + (Diff / Inc);
  LFO_Pulse = (_state.state.lfoPulseA * diffInc);
  LFO_Saw = (_state.state.lfoSawA * (diffInc - Diff));
  LFO_Tri = (_state.state.lfoTriangleA * (0.5f - Inc));
  _state.state.lfoPhase = (_state.state.lfoPhase - 1.0f);
  _state.state.lfoPulseSign = false;
  _state.state.lfoSh = (_state.state.lfoShA * _state.state.noiseFilterLPF);
  if (_state.state.repeatActive)
  {
      {
          v = {};
          for (;;)
          {
   if (v >= int32_t {32})
   {
       break;
   }
   if (v == _state.activeVoices)
   {
       break;
   }
   if ((_state.voices[v].gate > 0.0f) ? true : static_cast<bool> (_state.state.unisonGate))
   {
       _state.voices[v].isActive = true;
       peakA = 0.5f + (_state.state.velocityAmp * ((_state.voices[v].gate * 0.0078125f) - 0.5f));
       peakF = 0.5f + (_state.state.velocityFilter * ((_state.voices[v].gate * 0.0078125f) - 0.5f));
       if (_state.voices[v].envelopeA_Out > peakA)
       {
_state.voices[v].envelopeA_Peak = _state.voices[v].envelopeA_Out;
_state.voices[v].envelopeA_Stage = int32_t {1};
_state.voices[v].envelopeA_Fac = _state.state.envelopeA_D_FAC;
_state.voices[v].envelopeA_Level = (((_state.voices[v].envelopeA_Peak - envelopeAOffset) * _state.state.envelopeA_Sus) + envelopeAOffset);
_state.voices[v].envelopeA_SDif = (_state.voices[v].envelopeA_Peak - _state.voices[v].envelopeA_Level);
       }
       else
       {
_state.voices[v].envelopeA_Inc = (peakA * _state.state.envelopeA_Att);
_state.voices[v].envelopeA_Peak = peakA;
_state.voices[v].envelopeA_Stage = int32_t {0};
       }
       if (_state.voices[v].envelopeF_Out > peakF)
       {
_state.voices[v].envelopeF_Peak = _state.voices[v].envelopeF_Out;
_state.voices[v].envelopeF_Stage = int32_t {1};
_state.voices[v].envelopeF_Fac = _state.state.envelopeF_D_FAC;
_state.voices[v].envelopeF_Level = (_state.voices[v].envelopeF_Peak * _state.state.envelopeF_Sus);
_state.voices[v].envelopeF_SDif = (_state.voices[v].envelopeF_Out - _state.voices[v].envelopeF_Level);
       }
       else
       {
_state.voices[v].envelopeF_Inc = (peakF * _state.state.envelopeF_Att);
_state.voices[v].envelopeF_Peak = peakF;
_state.voices[v].envelopeF_Stage = int32_t {0};
_state.voices[v].envelopeF_SDif = 1.0f;
       }
   }
   {
       ++v;
   }
          }
      }
  }
         }
     }
     else
     {
         Diff_0 = 0.5f - _state.state.lfoPhase;
         if (Diff_0 > (0.5f * Inc))
         {
  LFO_Pulse = 0.0f;
  LFO_Tri = (_state.state.lfoTriangleA * (0.5f - (2.0f * _state.state.lfoPhase)));
         }
         else
         {
  LFO_Pulse = (_state.state.lfoPulseA * (0.5f - (Diff_0 / Inc)));
  LFO_Tri = (_state.state.lfoTriangleA * (-0.5f + Inc));
  _state.state.lfoPulseSign = true;
  if (_state.state.repeatActive)
  {
      {
          v_0 = {};
          for (;;)
          {
   {
       if (v_0 >= int32_t {32})
       {
break;
       }
       if (v_0 == _state.activeVoices)
       {
break;
       }
       if (! _state.voices[v_0].isActive)
       {
goto _break_0;
       }
       if ((_state.voices[v_0].gate > 0.0f) ? true : static_cast<bool> (_state.state.unisonGate))
       {
_state.voices[v_0].envelopeA_Stage = int32_t {2};
_state.voices[v_0].envelopeA_Fac = _state.state.envelopeA_R_FAC;
_state.voices[v_0].envelopeA_Level = envelopeAOffset;
_state.voices[v_0].envelopeA_SDif = (_state.voices[v_0].envelopeA_Out - _state.voices[v_0].envelopeA_Level);
_state.voices[v_0].envelopeF_Stage = int32_t {2};
_state.voices[v_0].envelopeF_Fac = _state.state.envelopeF_R_FAC;
_state.voices[v_0].envelopeF_Level = 0.0f;
_state.voices[v_0].envelopeF_SDif = (_state.voices[v_0].envelopeF_Out - _state.voices[v_0].envelopeF_Level);
       }
   }
   _break_0: {}
   {
       ++v_0;
   }
          }
      }
  }
         }
         LFO_Saw = (_state.state.lfoSawA * _state.state.lfoPhase);
     }
 }
 {
     Wort = _state.state.noiseMem;
     Feedback = ((Wort ^ (Wort >> static_cast<int64_t> (int32_t {5}))) ^ (Wort >> static_cast<int64_t> (int32_t {13}))) << static_cast<int64_t> (int32_t {31});
     Feedback = (Feedback & int64_t {0xffffffffL});
     Wort = (Wort >> static_cast<int64_t> (int32_t {1}));
     Wort = (Wort | Feedback);
     Noise_White = (-0.5f + static_cast<float> (Wort & static_cast<int64_t> (int32_t {1})));
     _state.state.noiseMem = Wort;
 }
 {
     Hpf = Noise_White - _state.state.noiseFilterLPF;
     _state.state.noiseFilterLPF = (_state.state.noiseFilterLPF + (Hpf * _state.state.noiseFilterFreq));
     Noise_Filtered = _state.state.noiseFilterLPF;
 }
 {
     In1 = (((LFO_Pulse + LFO_Saw) + LFO_Tri) + _state.state.lfoSh) + _state.state.lfoConst;
     In2 = Noise_Filtered;
     WheelMod = (In1 + (_state.state.lfoNoiseMix * (In2 - In1))) * _state.state.modulationWheel;
     PulseWidthA = (_state.state.oscillatorA_PW + (_state.state.oscillatorA_PW_WM * WheelMod));
     PulseWidthB = (_state.state.oscillatorB_PW + (_state.state.oscillatorB_PW_WM * WheelMod));
     PulseWidthB = intrinsics::clamp (PulseWidthB, -1.0f, 1.0f);
     WheelMod2OscAFm = (_state.state.oscillatorA_FM_WM * WheelMod);
     WheelMod2OscBFm = (_state.state.oscillatorB_FM_WM * WheelMod);
     WheelMod2Filt = (_state.state.filter_WM * WheelMod);
 }
 _state.state.controlCount = (_state.state.controlCount + -1.0f);
 if (_state.state.controlCount <= static_cast<float> (int32_t {0}))
 {
     _state.state.controlCount = static_cast<float> (controlPeriod);
     if (_state.state.knobSmoothingCounter != int32_t {0})
     {
         --_state.state.knobSmoothingCounter;
         _state.state.mixerOscillatorA = (_state.state.mixerOscillatorA + _state.state.mixerOscillatorA_Inc);
         _state.state.mixerOscillatorB = (_state.state.mixerOscillatorB + _state.state.mixerOscillatorB_Inc);
         _state.state.oscillatorA_SawA = (_state.state.mixerOscillatorA * _state.state.oscillatorA_SawActive);
         _state.state.oscillatorA_PW = (_state.state.oscillatorA_PW + _state.state.oscillatorA_PW_Inc);
         _state.state.oscillatorB_PW = (_state.state.oscillatorB_PW + _state.state.oscillatorB_PW_Inc);
         _state.state.filter_Event = (_state.state.filter_Event + _state.state.filter_EventInc);
         {
  v_1 = {};
  for (;;)
  {
      if (v_1 >= int32_t {32})
      {
          break;
      }
      if (v_1 == _state.activeVoices)
      {
          break;
      }
      _state.voices[v_1].filter_Event = (_state.state.filter_Event + _state.voices[v_1].filter_RND);
      {
          ++v_1;
      }
  }
         }
         _state.state.filter_Env = (_state.state.filter_Env + _state.state.filter_EnvInc);
         _state.state.filter_Keyboard = (_state.state.filter_Keyboard + _state.state.filter_KeyboardInc);
     }
     if (_state.state.glideInc != 0.0f)
     {
         _state.state.glideOut = (_state.state.glideOut + _state.state.glideInc);
         if (((_state.state.glideOut - _state.state.glideFinal) * _state.state.glideInc) > 0.0f)
         {
  _state.state.glideOut = _state.state.glideFinal;
  _state.state.glideInc = 0.0f;
         }
         {
  v_2 = {};
  for (;;)
  {
      if (v_2 >= int32_t {32})
      {
          break;
      }
      if (v_2 == _state.activeVoices)
      {
          break;
      }
      _state.voices[v_2].pitch = (_state.state.glideOut + _state.voices[v_2].unisonRnd);
      _state.voices[v_2].oscillatorA_F = Engine__pitchToFreq (_state, _state.voices[v_2].pitch + _state.voices[v_2].oscillatorA_Tune);
      _state.voices[v_2].oscillatorB_F = Engine__pitchToFreq (_state, (_state.state.oscillatorB_Keyboard * _state.voices[v_2].pitch) + _state.voices[v_2].oscillatorB_Tune);
      {
          ++v_2;
      }
  }
         }
     }
     {
         v_3 = {};
         for (;;)
         {
  {
      if (v_3 >= int32_t {32})
      {
          break;
      }
      if (v_3 == _state.activeVoices)
      {
          break;
      }
      if (! _state.voices[v_3].isActive)
      {
          goto _break_1;
      }
      final_ = Engine__pitchToFreq (_state, ((WheelMod2Filt + (_state.state.filter_Env * _state.voices[v_3].envelopeF_Out)) + _state.voices[v_3].filter_Event) + (_state.state.filter_Keyboard * _state.voices[v_3].pitch));
      _state.voices[v_3].filter_F_Inc = ((final_ - _state.voices[v_3].filter_F_Smooth) * 0.8f);
      if (_state.voices[v_3].envelopeA_Out < 0.0f)
      {
          _state.voices[v_3].envelopeA_Out = 0.0f;
          _state.voices[v_3].envelopeA_SDif = 0.0f;
          _state.voices[v_3].envelopeA_Level = 0.0f;
          _state.voices[v_3].envelopeF_Out = 0.0f;
          _state.voices[v_3].isActive = false;
      }
      else
      {
          if (_state.voices[v_3].envelopeA_SDif < 0.0001f)
          {
   if (_state.voices[v_3].envelopeA_SDif > -0.0001f)
   {
       _state.voices[v_3].envelopeA_SDif = 0.0f;
       _state.voices[v_3].envelopeA_Level = _state.voices[v_3].envelopeA_Out;
   }
          }
      }
      if (_state.voices[v_3].envelopeF_SDif < 0.0001f)
      {
          if (_state.voices[v_3].envelopeF_SDif > -0.0001f)
          {
   _state.voices[v_3].envelopeF_SDif = 0.0f;
   _state.voices[v_3].envelopeF_Level = _state.voices[v_3].envelopeF_Out;
          }
      }
      if (static_cast<double> (_state.voices[v_3].filter1HP_LPF * _state.voices[v_3].filter1HP_LPF) < 1e-7)
      {
          _state.voices[v_3].filter1HP_LPF = 0.0f;
      }
  }
  _break_1: {}
  {
      ++v_3;
  }
         }
     }
     if (_state.state.delayActive)
     {
         tri = {};
         final__0 = {};
         _state.state.delayLFO_Pos_1 = (_state.state.delayLFO_Pos_1 + ((_state.state.delayRate_1 * static_cast<float> (int32_t {4})) * _state.tau));
         if (_state.state.delayLFO_Pos_1 > 1.0f)
         {
  if (_state.state.delayLFO_Pos_1 > 3.0f)
  {
      _state.state.delayLFO_Pos_1 = (_state.state.delayLFO_Pos_1 - 4.0f);
      tri = _state.state.delayLFO_Pos_1;
  }
  else
  {
      tri = (2.0f - _state.state.delayLFO_Pos_1);
  }
         }
         else
         {
  tri = _state.state.delayLFO_Pos_1;
         }
         final__0 = (_state.state.delayTime_1 + (_state.state.delayDepth * tri));
         _state.state.delayTime_Inc_1 = (((final__0 - _state.state.delayTime_Mod_1) * _state.tau) * static_cast<float> (int32_t {25}));
         if (_state.state.delaySync)
         {
  final__0 = (_state.state.delayTime_2 + (_state.state.delayDepth * tri));
  _state.state.delayTime_Inc_2 = (((final__0 - _state.state.delayTime_Mod_2) * _state.tau) * static_cast<float> (int32_t {25}));
  final__0 = (_state.state.delayTime_3 + (_state.state.delayDepth * tri));
  _state.state.delayTime_Inc_3 = (((final__0 - _state.state.delayTime_Mod_3) * _state.tau) * static_cast<float> (int32_t {25}));
  final__0 = (_state.state.delayTime_4 + (_state.state.delayDepth * tri));
  _state.state.delayTime_Inc_4 = (((final__0 - _state.state.delayTime_Mod_4) * _state.tau) * static_cast<float> (int32_t {25}));
         }
         else
         {
  _state.state.delayLFO_Pos_2 = (_state.state.delayLFO_Pos_2 + ((_state.state.delayRate_2 * static_cast<float> (int32_t {4})) * _state.tau));
  if (_state.state.delayLFO_Pos_2 > 1.0f)
  {
      if (_state.state.delayLFO_Pos_2 > 3.0f)
      {
          _state.state.delayLFO_Pos_2 = (_state.state.delayLFO_Pos_2 - 4.0f);
          tri = _state.state.delayLFO_Pos_2;
      }
      else
      {
          tri = (2.0f - _state.state.delayLFO_Pos_2);
      }
  }
  else
  {
      tri = _state.state.delayLFO_Pos_2;
  }
  final__0 = (_state.state.delayTime_2 + (_state.state.delayDepth * tri));
  _state.state.delayTime_Inc_2 = (((final__0 - _state.state.delayTime_Mod_2) * _state.tau) * static_cast<float> (int32_t {25}));
  _state.state.delayLFO_Pos_3 = (_state.state.delayLFO_Pos_3 + ((_state.state.delayRate_3 * static_cast<float> (int32_t {4})) * _state.tau));
  if (_state.state.delayLFO_Pos_3 > 1.0f)
  {
      if (_state.state.delayLFO_Pos_3 > 3.0f)
      {
          _state.state.delayLFO_Pos_3 = (_state.state.delayLFO_Pos_3 - 4.0f);
          tri = _state.state.delayLFO_Pos_3;
      }
      else
      {
          tri = (2.0f - _state.state.delayLFO_Pos_3);
      }
  }
  else
  {
      tri = _state.state.delayLFO_Pos_3;
  }
  final__0 = (_state.state.delayTime_3 + (_state.state.delayDepth * tri));
  _state.state.delayTime_Inc_3 = (((final__0 - _state.state.delayTime_Mod_3) * _state.tau) * static_cast<float> (int32_t {25}));
  _state.state.delayLFO_Pos_4 = (_state.state.delayLFO_Pos_4 + ((_state.state.delayRate_4 * static_cast<float> (int32_t {4})) * _state.tau));
  if (_state.state.delayLFO_Pos_4 > 1.0f)
  {
      if (_state.state.delayLFO_Pos_4 > 3.0f)
      {
          _state.state.delayLFO_Pos_4 = (_state.state.delayLFO_Pos_4 - 4.0f);
          tri = _state.state.delayLFO_Pos_4;
      }
      else
      {
          tri = (2.0f - _state.state.delayLFO_Pos_4);
      }
  }
  else
  {
      tri = _state.state.delayLFO_Pos_4;
  }
  final__0 = (_state.state.delayTime_4 + (_state.state.delayDepth * tri));
  _state.state.delayTime_Inc_4 = (((final__0 - _state.state.delayTime_Mod_4) * _state.tau) * static_cast<float> (int32_t {25}));
         }
     }
 }
 inputSignal = _io.externalIn * _state.state.mixerExternal;
 voiceOutput = {};
 {
     v_4 = {};
     for (;;)
     {
         {
  if (v_4 >= int32_t {32})
  {
      break;
  }
  if (v_4 == _state.activeVoices)
  {
      break;
  }
  if (! _state.voices[v_4].isActive)
  {
      goto _break_2;
  }
  if (_state.voices[v_4].envelopeA_Stage != int32_t {0})
  {
      _state.voices[v_4].envelopeA_SDif = (_state.voices[v_4].envelopeA_SDif * _state.voices[v_4].envelopeA_Fac);
      _state.voices[v_4].envelopeA_Out = (_state.voices[v_4].envelopeA_Level + _state.voices[v_4].envelopeA_SDif);
  }
  else
  {
      _state.voices[v_4].envelopeA_Out = (_state.voices[v_4].envelopeA_Out + _state.voices[v_4].envelopeA_Inc);
      if (_state.voices[v_4].envelopeA_Out > _state.voices[v_4].envelopeA_Peak)
      {
          _state.voices[v_4].envelopeA_Out = _state.voices[v_4].envelopeA_Peak;
          _state.voices[v_4].envelopeA_Stage = int32_t {1};
          _state.voices[v_4].envelopeA_Fac = _state.state.envelopeA_D_FAC;
          _state.voices[v_4].envelopeA_Level = (((_state.voices[v_4].envelopeA_Peak - envelopeAOffset) * _state.state.envelopeA_Sus) + envelopeAOffset);
          _state.voices[v_4].envelopeA_SDif = (_state.voices[v_4].envelopeA_Peak - _state.voices[v_4].envelopeA_Level);
      }
  }
  if (_state.voices[v_4].envelopeF_Stage != int32_t {0})
  {
      _state.voices[v_4].envelopeF_SDif = (_state.voices[v_4].envelopeF_SDif * _state.voices[v_4].envelopeF_Fac);
      _state.voices[v_4].envelopeF_Out = (_state.voices[v_4].envelopeF_Level + _state.voices[v_4].envelopeF_SDif);
  }
  else
  {
      _state.voices[v_4].envelopeF_Out = (_state.voices[v_4].envelopeF_Out + _state.voices[v_4].envelopeF_Inc);
      if (_state.voices[v_4].envelopeF_Out > _state.voices[v_4].envelopeF_Peak)
      {
          _state.voices[v_4].envelopeF_Out = _state.voices[v_4].envelopeF_Peak;
          _state.voices[v_4].envelopeF_Stage = int32_t {1};
          _state.voices[v_4].envelopeF_Fac = _state.state.envelopeF_D_FAC;
          _state.voices[v_4].envelopeF_Level = (_state.voices[v_4].envelopeF_Peak * _state.state.envelopeF_Sus);
          _state.voices[v_4].envelopeF_SDif = (_state.voices[v_4].envelopeF_Peak - _state.voices[v_4].envelopeF_Level);
          final__1 = Engine__pitchToFreq (_state, ((WheelMod2Filt + (_state.state.filter_Env * _state.voices[v_4].envelopeF_Out)) + _state.voices[v_4].filter_Event) + (_state.state.filter_Keyboard * _state.voices[v_4].pitch));
          _state.voices[v_4].filter_F_Inc = ((final__1 - _state.voices[v_4].filter_F_Smooth) * 0.8f);
      }
  }
  useNewOsc = false;
  if (useNewOsc)
  {
      f = (_state.voices[v_4].oscillatorB_F + (_state.voices[v_4].oscillatorB_F * WheelMod2OscBFm)) * _state.tau;
      if (intrinsics::abs (f) > 0.99f)
      {
          f = ((f > static_cast<float> (int32_t {0})) ? 0.99f : -0.99f);
      }
      ph = _state.voices[v_4].oscillatorB_Phase;
      newph = ph + f;
      level = static_cast<float> (_state.voices[v_4].oscillatorB_PulseLevel - int32_t {1});
      if (intrinsics::abs (newph) >= static_cast<float> (int32_t {1}))
      {
          cposMain = (intrinsics::abs (newph) - 1.0f) / intrinsics::abs (f);
          sgnf = (f > static_cast<float> (int32_t {0})) ? 1.0f : -1.0f;
          pwmain = Engine__xfade (PulseWidthB, _state.voices[v_4].oscillatorB_PW_OLD, cposMain);
          if (((sgnf - pwmain) * level) > static_cast<float> (int32_t {0}))
          {
   cpos = (Engine__findPWT (sgnf, pwmain, ph, _state.voices[v_4].oscillatorB_PW_OLD) * (static_cast<float> (int32_t {1}) - cposMain)) + cposMain;
   Engine__addBlep0 (_state.voices[v_4].oscillatorB_BUF, _state.voices[v_4].oscillatorB_BUFWRITE, int32_t {7}, cpos, (-2.0f * _state.state.oscillatorB_PulseA) * level);
   level = (- level);
   _state.voices[v_4].oscillatorB_PulseLevel = (_state.voices[v_4].oscillatorB_PulseLevel ^ int32_t {2});
          }
          Engine__addBlep0 (_state.voices[v_4].oscillatorB_BUF, _state.voices[v_4].oscillatorB_BUFWRITE, int32_t {7}, cposMain, (- sgnf) * (_state.state.oscillatorB_SawA + _state.state.oscillatorB_PulseA));
          newph = (newph - (2.0f * sgnf));
          level = (- level);
          _state.voices[v_4].oscillatorB_PulseLevel = (_state.voices[v_4].oscillatorB_PulseLevel ^ int32_t {2});
          if (((newph - PulseWidthB) * level) > static_cast<float> (int32_t {0}))
          {
   cpos_0 = Engine__findPWT (newph, PulseWidthB, - sgnf, pwmain) * cposMain;
   Engine__addBlep0 (_state.voices[v_4].oscillatorB_BUF, _state.voices[v_4].oscillatorB_BUFWRITE, int32_t {7}, cpos_0, (-2.0f * _state.state.oscillatorB_PulseA) * level);
   level = (- level);
   _state.voices[v_4].oscillatorB_PulseLevel = (_state.voices[v_4].oscillatorB_PulseLevel ^ int32_t {2});
          }
      }
      else
      {
          if (((newph - PulseWidthB) * level) > static_cast<float> (int32_t {0}))
          {
   cpos_1 = Engine__findPWT (newph, PulseWidthB, ph, _state.voices[v_4].oscillatorB_PW_OLD);
   Engine__addBlep0 (_state.voices[v_4].oscillatorB_BUF, _state.voices[v_4].oscillatorB_BUFWRITE, int32_t {7}, cpos_1, (-2.0f * _state.state.oscillatorB_PulseA) * level);
   level = (- level);
   _state.voices[v_4].oscillatorB_PulseLevel = (_state.voices[v_4].oscillatorB_PulseLevel ^ int32_t {2});
          }
      }
      _state.voices[v_4].oscillatorB_BUF[_state.voices[v_4].oscillatorB_BUFWRITE & int32_t {7}] = (_state.voices[v_4].oscillatorB_BUF[_state.voices[v_4].oscillatorB_BUFWRITE & int32_t {7}] + ((newph * _state.state.oscillatorB_SawA) + (level * _state.state.oscillatorB_PulseA)));
      _state.voices[v_4].oscillatorB_Phase = newph;
      out = _state.voices[v_4].oscillatorB_BUF[((_state.voices[v_4].oscillatorB_BUFWRITE - int32_t {2}) & int32_t {7}) & int32_t {7}];
      _state.voices[v_4].oscillatorB_BUFWRITE = ((_state.voices[v_4].oscillatorB_BUFWRITE + int32_t {1}) & int32_t {7});
      OscB_All = out;
      _state.voices[v_4].oscillatorB_BUF[((_state.voices[v_4].oscillatorB_BUFWRITE - int32_t {2}) & int32_t {7}) & int32_t {7}] = 0.0f;
      _state.voices[v_4].oscillatorB_PW_OLD = PulseWidthB;
  }
  else
  {
      f_0 = (_state.voices[v_4].oscillatorB_F + (_state.voices[v_4].oscillatorB_F * WheelMod2OscBFm)) * _state.tau;
      ph_0 = _state.voices[v_4].oscillatorB_Phase;
      f_0 = intrinsics::max (f_0, 0.0f);
      if (f_0 >= 1.0f)
      {
          ph_0 = 0.0f;
          OscB_Saw = 0.0f;
          OscB_Pulse = 0.0f;
          OscB_Tri = 0.0f;
          oscillatorSyncNow = false;
      }
      else
      {
          ph_0 = (ph_0 + f_0);
          if (ph_0 >= 1.0f)
          {
   oscillatorSyncNow = _state.state.oscillatorSyncActive;
   ph_0 = (ph_0 - 2.0f);
   d = 1.0f + ph_0;
   f_rcp = 1.0f / f_0;
   x = d * f_rcp;
   x_1 = x - 1.0f;
   Osc_Sync_x = x;
   aa_dn_1 = 2.0f - (x * x);
   y_saw = (ph_0 + _state.voices[v_4].oscillatorB_Saw_AA2) + aa_dn_1;
   aa_dn_2 = x_1 * x_1;
   _state.voices[v_4].oscillatorB_Saw_AA2 = aa_dn_2;
   OscB_Saw = (_state.state.oscillatorB_SawA * (y_saw + 1.0f));
   if (_state.state.oscillatorB_PulseA != static_cast<float> (int32_t {0}))
   {
       ph_pwm = PulseWidthB;
       ph2 = ph_0 - ph_pwm;
       ph2_sign = Engine__sign (ph2);
       ph3 = Engine__getPhase (ph2);
       pulse_aa_2 = _state.voices[v_4].oscillatorB_Pulse_AA2;
       if ((ph3 * (ph3 - f_0)) < 0.0f)
       {
ph3_abs = intrinsics::abs (ph3);
x3 = ph3_abs * f_rcp;
x3_1 = x3 - 1.0f;
aa_up_1 = 2.0f - (x3 * x3);
aa_up_2 = x3_1 * x3_1;
y_pulse = ((ph2_sign + pulse_aa_2) + aa_dn_1) - aa_up_1;
pulse_aa_2 = (aa_dn_2 - aa_up_2);
OscB_Pulse = (0.5f - (0.5f * y_pulse));
       }
       else
       {
y_pulse_0 = (ph2_sign + pulse_aa_2) + aa_dn_1;
pulse_aa_2 = aa_dn_2;
OscB_Pulse = (0.5f - (0.5f * y_pulse_0));
       }
       _state.voices[v_4].oscillatorB_Pulse_AA2 = pulse_aa_2;
   }
   else
   {
       OscB_Pulse = 0.0f;
   }
   if (_state.state.oscillatorB_TriA)
   {
       if ((ph_0 * (ph_0 - f_0)) < 0.0f)
       {
aa_top = (x * (2.0f - x)) - 1.0f;
aa_btm = 1.0f - (f_rcp * (2.0f + f_rcp));
OscB_Tri = ((0.5f - ((0.5f * f_0) - ph_0)) - (f_0 * (aa_top - aa_btm)));
       }
       else
       {
aa_top_0 = (x * (2.0f - x)) - 1.0f;
OscB_Tri = ((0.5f - ((0.5f * f_0) - ph_0)) - (f_0 * aa_top_0));
       }
   }
   else
   {
       OscB_Tri = 0.0f;
   }
          }
          else
          {
   oscillatorSyncNow = false;
   y_saw_0 = ph_0 + _state.voices[v_4].oscillatorB_Saw_AA2;
   _state.voices[v_4].oscillatorB_Saw_AA2 = 0.0f;
   OscB_Saw = (_state.state.oscillatorB_SawA * (y_saw_0 + 1.0f));
   if (_state.state.oscillatorB_PulseA != static_cast<float> (int32_t {0}))
   {
       ph_pwm_0 = PulseWidthB;
       ph2_0 = ph_0 - ph_pwm_0;
       ph2_sign_0 = Engine__sign (ph2_0);
       ph3_0 = Engine__getPhase (ph2_0);
       pulse_aa_2_0 = _state.voices[v_4].oscillatorB_Pulse_AA2;
       if ((ph3_0 * (ph3_0 - f_0)) < 0.0f)
       {
ph3_abs_0 = intrinsics::abs (ph3_0);
x3_0 = ph3_abs_0 / f_0;
x3_1_0 = x3_0 - 1.0f;
aa_up_1_0 = 2.0f - (x3_0 * x3_0);
aa_up_2_0 = x3_1_0 * x3_1_0;
y_pulse_1 = (ph2_sign_0 + pulse_aa_2_0) - aa_up_1_0;
pulse_aa_2_0 = (- aa_up_2_0);
OscB_Pulse = (0.5f - (0.5f * y_pulse_1));
       }
       else
       {
y_pulse_2 = ph2_sign_0 + pulse_aa_2_0;
pulse_aa_2_0 = 0.0f;
OscB_Pulse = (0.5f - (0.5f * y_pulse_2));
       }
       _state.voices[v_4].oscillatorB_Pulse_AA2 = pulse_aa_2_0;
   }
   else
   {
       OscB_Pulse = 0.0f;
   }
   if (_state.state.oscillatorB_TriA)
   {
       ph_sign = Engine__sign (ph_0);
       if ((ph_0 * (ph_0 - f_0)) < static_cast<float> (int32_t {0}))
       {
ph_abs = intrinsics::abs (ph_0);
x5 = ph_abs / f_0;
aa_btm_0 = (x5 * (2.0f - x5)) - 1.0f;
OscB_Tri = ((0.5f + (ph_sign * ((0.5f * f_0) - ph_0))) + (f_0 * aa_btm_0));
       }
       else
       {
OscB_Tri = (0.5f + (ph_sign * ((0.5f * f_0) - ph_0)));
       }
   }
   else
   {
       OscB_Tri = 0.0f;
   }
          }
      }
      _state.voices[v_4].oscillatorB_Phase = ph_0;
  }
  if (useNewOsc)
  {
      PolyMod = ((_state.state.polymodOscillatorB * OscB_All) + (_state.state.polymodEnvelopeF * (_state.voices[v_4].envelopeF_Out * _state.voices[v_4].polymodEnvRnd)));
  }
  else
  {
      OscB_PulseTri = (OscB_Pulse + OscB_Tri);
      PolyMod = ((_state.state.polymodOscillatorB * (OscB_Saw + OscB_PulseTri)) + (_state.state.polymodEnvelopeF * (_state.voices[v_4].envelopeF_Out * _state.voices[v_4].polymodEnvRnd)));
  }
  {
      f_1 = (_state.voices[v_4].oscillatorA_F + (_state.voices[v_4].oscillatorA_F * (WheelMod2OscAFm + (_state.state.oscillatorA_FM_PM * PolyMod)))) * _state.tau;
      f_1 = intrinsics::max (f_1, 0.0f);
      ph_1 = _state.voices[v_4].oscillatorA_Phase;
      if (f_1 >= 1.0f)
      {
          ph_1 = 0.0f;
          OscA_Saw = 0.0f;
          OscA_Pulse = 0.0f;
      }
      else
      {
          ph_1 = (ph_1 + f_1);
          if (oscillatorSyncNow)
          {
   x_snc = Osc_Sync_x;
   x_snc_1 = x_snc - 1.0f;
   d_snc = x_snc * f_1;
   snc_ph = d_snc - 1.0f;
   ph_adj = ph_1 - d_snc;
   if (ph_adj >= 1.0f)
   {
       ph_1 = (ph_1 - 2.0f);
       ph_abs_0 = intrinsics::abs (ph_1);
       d_0 = 1.0f - ph_abs_0;
       f_rcp_0 = 1.0f / f_1;
       x_0 = d_0 * f_rcp_0;
       x_1_0 = x_0 - 1.0f;
       ph2_1 = ph_1;
       ph_snc_change = snc_ph - ph_1;
       ph_1 = (ph_1 + ph_snc_change);
       snc_aa_amp = -0.5f * ph_snc_change;
       aa_dn_1_0 = 2.0f - (x_0 * x_0);
       aa_snc_1 = 2.0f - (x_snc * x_snc);
       aa_snc_1_saw = aa_snc_1 * snc_aa_amp;
       aa_dn_2_0 = x_1_0 * x_1_0;
       aa_snc_2 = x_snc_1 * x_snc_1;
       aa_snc_2_saw = aa_snc_2 * snc_aa_amp;
       y_saw_1 = ((ph_1 + _state.voices[v_4].oscillatorA_Saw_AA2) + aa_dn_1_0) + aa_snc_1_saw;
       _state.voices[v_4].oscillatorA_Saw_AA2 = (aa_dn_2_0 + aa_snc_2_saw);
       OscA_Saw = (_state.state.oscillatorA_SawA * y_saw_1);
       if (_state.state.oscillatorA_PulseActive)
       {
ph_pwm_1 = PulseWidthA + (_state.state.oscillatorA_PW_PM * PolyMod);
ph_pwm_1 = intrinsics::clamp (ph_pwm_1, -1.0f, 1.0f);
ph2_1 = (ph2_1 - ph_pwm_1);
ph3_1 = Engine__getPhase (ph2_1);
ph4 = ph2_1 + ph_snc_change;
aa_up_snc_1 = {};
aa_up_snc_2 = {};
if ((ph4 * ((ph4 + ph_snc_change) - f_1)) < 0.0f)
{
    x4 = intrinsics::abs (ph4) * f_rcp_0;
    x4_1 = x4 - 1.0f;
    aa_up_snc_1 = (2.0f - (x4 * x4));
    aa_up_snc_2 = (x4_1 * x4_1);
}
else
{
    aa_up_snc_1 = 0.0f;
    aa_up_snc_2 = 0.0f;
}
aa_snc_1_pulse = {};
aa_snc_2_pulse = {};
if ((ph2_1 - d_snc) > 0.0f)
{
    aa_snc_1_pulse = aa_snc_1;
    aa_snc_2_pulse = aa_snc_2;
}
else
{
    aa_snc_1_pulse = 0.0f;
    aa_snc_2_pulse = 0.0f;
}
ph2_sign_1 = Engine__sign (ph_1 - ph_pwm_1);
pulse_aa_2_1 = _state.voices[v_4].oscillatorA_Pulse_AA2;
if (((ph3_1 - d_snc) * (ph3_1 - f_1)) < 0.0f)
{
    ph3_abs_1 = intrinsics::abs (ph3_1);
    x3_2 = ph3_abs_1 * f_rcp_0;
    x3_1_1 = x3_2 - 1.0f;
    aa_up_1_1 = 2.0f - (x3_2 * x3_2);
    aa_up_2_1 = x3_1_1 * x3_1_1;
    y_pulse_3 = ((((ph2_sign_1 + pulse_aa_2_1) + aa_dn_1_0) - aa_up_1_1) - aa_up_snc_1) + aa_snc_1_pulse;
    pulse_aa_2_1 = (((aa_dn_2_0 - aa_up_2_1) - aa_up_snc_2) + aa_snc_2_pulse);
    OscA_Pulse = (_state.state.mixerOscillatorA * y_pulse_3);
}
else
{
    y_pulse_4 = (((ph2_sign_1 + pulse_aa_2_1) + aa_dn_1_0) - aa_up_snc_1) + aa_snc_1_pulse;
    pulse_aa_2_1 = ((aa_dn_2_0 - aa_up_snc_2) + aa_snc_2_pulse);
    OscA_Pulse = (_state.state.mixerOscillatorA * y_pulse_4);
}
_state.voices[v_4].oscillatorA_Pulse_AA2 = pulse_aa_2_1;
       }
       else
       {
OscA_Pulse = 0.0f;
       }
   }
   else
   {
       ph2_2 = ph_1;
       ph_snc_change_0 = snc_ph - ph_1;
       ph_1 = (ph_1 + ph_snc_change_0);
       snc_aa_amp_0 = -0.5f * ph_snc_change_0;
       aa_snc_1_0 = 2.0f - (x_snc * x_snc);
       aa_snc_1_saw_0 = aa_snc_1_0 * snc_aa_amp_0;
       aa_snc_2_0 = x_snc_1 * x_snc_1;
       aa_snc_2_saw_0 = aa_snc_2_0 * snc_aa_amp_0;
       y_saw_2 = (ph_1 + _state.voices[v_4].oscillatorA_Saw_AA2) + aa_snc_1_saw_0;
       _state.voices[v_4].oscillatorA_Saw_AA2 = aa_snc_2_saw_0;
       OscA_Saw = (_state.state.oscillatorA_SawA * y_saw_2);
       if (_state.state.oscillatorA_PulseActive)
       {
ph_pwm_2 = intrinsics::clamp (PulseWidthA + (_state.state.oscillatorA_PW_PM * PolyMod), -1.0f, 1.0f);
ph2_2 = (ph2_2 - ph_pwm_2);
ph3_2 = Engine__getPhase (ph2_2);
ph4_0 = ph2_2 + ph_snc_change_0;
aa_up_snc_1_0 = {};
aa_up_snc_2_0 = {};
if ((ph4_0 * ((ph4_0 + ph_snc_change_0) - f_1)) < 0.0f)
{
    x4_0 = intrinsics::abs (ph4_0) / f_1;
    x4_1_0 = x4_0 - 1.0f;
    aa_up_snc_1_0 = (2.0f - (x4_0 * x4_0));
    aa_up_snc_2_0 = (x4_1_0 * x4_1_0);
}
aa_snc_1_pulse_0 = {};
aa_snc_2_pulse_0 = {};
if ((ph2_2 - d_snc) > 0.0f)
{
    aa_snc_1_pulse_0 = aa_snc_1_0;
    aa_snc_2_pulse_0 = aa_snc_2_0;
}
else
{
    aa_snc_1_pulse_0 = 0.0f;
    aa_snc_2_pulse_0 = 0.0f;
}
ph2_sign_2 = Engine__sign (ph_1 - ph_pwm_2);
pulse_aa_2_2 = _state.voices[v_4].oscillatorA_Pulse_AA2;
if (((ph3_2 - d_snc) * (ph3_2 - f_1)) < 0.0f)
{
    ph3_abs_2 = intrinsics::abs (ph3_2);
    x3_3 = ph3_abs_2 / f_1;
    x3_1_2 = x3_3 - 1.0f;
    aa_up_1_2 = 2.0f - (x3_3 * x3_3);
    aa_up_2_2 = x3_1_2 * x3_1_2;
    y_pulse_5 = (((ph2_sign_2 + pulse_aa_2_2) - aa_up_1_2) - aa_up_snc_1_0) + aa_snc_1_pulse_0;
    pulse_aa_2_2 = (((- aa_up_2_2) - aa_up_snc_2_0) + aa_snc_2_pulse_0);
    OscA_Pulse = (_state.state.mixerOscillatorA * y_pulse_5);
}
else
{
    y_pulse_6 = ((ph2_sign_2 + pulse_aa_2_2) - aa_up_snc_1_0) + aa_snc_1_pulse_0;
    pulse_aa_2_2 = ((- aa_up_snc_2_0) + aa_snc_2_pulse_0);
    OscA_Pulse = (_state.state.mixerOscillatorA * y_pulse_6);
}
_state.voices[v_4].oscillatorA_Pulse_AA2 = pulse_aa_2_2;
       }
       else
       {
OscA_Pulse = 0.0f;
       }
   }
          }
          else
          {
   if (ph_1 >= 1.0f)
   {
       ph_1 = (ph_1 - 2.0f);
       d_1 = 1.0f + ph_1;
       f_rcp_1 = 1.0f / f_1;
       x_2 = d_1 * f_rcp_1;
       x_1_1 = x_2 - 1.0f;
       aa_dn_1_1 = 2.0f - (x_2 * x_2);
       aa_dn_2_1 = x_1_1 * x_1_1;
       y_saw_3 = (ph_1 + _state.voices[v_4].oscillatorA_Saw_AA2) + aa_dn_1_1;
       _state.voices[v_4].oscillatorA_Saw_AA2 = aa_dn_2_1;
       OscA_Saw = (_state.state.oscillatorA_SawA * y_saw_3);
       if (_state.state.oscillatorA_PulseActive)
       {
ph_pwm_3 = intrinsics::clamp (PulseWidthA + (_state.state.oscillatorA_PW_PM * PolyMod), -1.0f, 1.0f);
ph2_3 = ph_1 - ph_pwm_3;
ph2_sign_3 = Engine__sign (ph2_3);
ph3_3 = Engine__getPhase (ph2_3);
pulse_aa_2_3 = _state.voices[v_4].oscillatorA_Pulse_AA2;
if ((ph3_3 * (ph3_3 - f_1)) < 0.0f)
{
    ph3_abs_3 = intrinsics::abs (ph3_3);
    x3_4 = ph3_abs_3 * f_rcp_1;
    x3_1_3 = x3_4 - 1.0f;
    aa_up_1_3 = 2.0f - (x3_4 * x3_4);
    aa_up_2_3 = x3_1_3 * x3_1_3;
    y_pulse_7 = ((ph2_sign_3 + pulse_aa_2_3) + aa_dn_1_1) - aa_up_1_3;
    pulse_aa_2_3 = (aa_dn_2_1 - aa_up_2_3);
    OscA_Pulse = (_state.state.mixerOscillatorA * y_pulse_7);
}
else
{
    y_pulse_8 = (ph2_sign_3 + pulse_aa_2_3) + aa_dn_1_1;
    pulse_aa_2_3 = aa_dn_2_1;
    OscA_Pulse = (_state.state.mixerOscillatorA * y_pulse_8);
}
_state.voices[v_4].oscillatorA_Pulse_AA2 = pulse_aa_2_3;
       }
       else
       {
OscA_Pulse = 0.0f;
       }
   }
   else
   {
       y_saw_4 = ph_1 + _state.voices[v_4].oscillatorA_Saw_AA2;
       _state.voices[v_4].oscillatorA_Saw_AA2 = 0.0f;
       OscA_Saw = (_state.state.oscillatorA_SawA * y_saw_4);
       if (_state.state.oscillatorA_PulseActive)
       {
ph_pwm_4 = intrinsics::clamp (PulseWidthA + (_state.state.oscillatorA_PW_PM * PolyMod), -1.0f, 1.0f);
ph2_4 = ph_1 - ph_pwm_4;
ph2_sign_4 = Engine__sign (ph2_4);
ph3_4 = Engine__getPhase (ph2_4);
pulse_aa_2_4 = _state.voices[v_4].oscillatorA_Pulse_AA2;
if ((ph3_4 * (ph3_4 - f_1)) < 0.0f)
{
    ph3_abs_4 = intrinsics::abs (ph3_4);
    x3_5 = ph3_abs_4 / f_1;
    x3_1_4 = x3_5 - 1.0f;
    aa_up_1_4 = 2.0f - (x3_5 * x3_5);
    aa_up_2_4 = x3_1_4 * x3_1_4;
    y_pulse_9 = (ph2_sign_4 + pulse_aa_2_4) - aa_up_1_4;
    pulse_aa_2_4 = (- aa_up_2_4);
    OscA_Pulse = (_state.state.mixerOscillatorA * y_pulse_9);
}
else
{
    y_pulse_10 = ph2_sign_4 + pulse_aa_2_4;
    pulse_aa_2_4 = 0.0f;
    OscA_Pulse = (_state.state.mixerOscillatorA * y_pulse_10);
}
_state.voices[v_4].oscillatorA_Pulse_AA2 = pulse_aa_2_4;
       }
       else
       {
OscA_Pulse = 0.0f;
       }
   }
          }
      }
      _state.voices[v_4].oscillatorA_Phase = ph_1;
  }
  if (useNewOsc)
  {
      EQ_Out = (_state.state.mixerOscillatorB * OscB_All);
  }
  else
  {
      EQ_In = (OscA_Pulse + OscA_Saw) + (_state.state.mixerOscillatorB * (OscB_Saw - OscB_PulseTri));
      EQ_Out = (EQ_In + (-0.171f * _state.voices[v_4].eqLast));
      _state.voices[v_4].eqLast = EQ_In;
  }
  Mixer = ((EQ_Out + (_state.state.mixerNoise * Noise_White)) + inputSignal);
  if (_state.filterVersion == int32_t {0})
  {
      satIn = {};
      {
          _state.voices[v_4].filter_F_Smooth = (_state.voices[v_4].filter_F_Smooth + _state.voices[v_4].filter_F_Inc);
          FM = (_state.state.filter_PM * PolyMod) * _state.voices[v_4].filter_F_Smooth;
          FN = (_state.voices[v_4].filter_F_Smooth + FM) * _state.tauFilter;
          F = FN;
          if (F < 0.0f)
          {
   FN = 0.0f;
   F = 0.0f;
          }
          else
          {
   if (F > _state.state.filterN_FMAX)
   {
       FN = _state.state.filterN_FMAX;
       if (F > _state.state.filter_FMAX)
       {
F = _state.state.filter_FMAX;
       }
   }
          }
          In = Mixer - _state.voices[v_4].saturator_Out;
          hpf = In - ((_state.voices[v_4].filter_BPF * _state.state.filter_D) + _state.voices[v_4].filter_LPF);
          _state.voices[v_4].filter_BPF = (_state.voices[v_4].filter_BPF + (hpf * F));
          _state.voices[v_4].filter_LPF = (_state.voices[v_4].filter_LPF + ((_state.voices[v_4].filter_BPF * F) + 1e-7f));
          if (_state.state.filter_HPF)
          {
   notch = hpf - _state.voices[v_4].filterN_BPF;
   hpf = ((notch * _state.state.filterN_D) - _state.voices[v_4].filterN_LPF);
   _state.voices[v_4].filterN_BPF = (_state.voices[v_4].filterN_BPF + (hpf * FN));
   _state.voices[v_4].filterN_LPF = (_state.voices[v_4].filterN_LPF + (_state.voices[v_4].filterN_BPF * FN));
   satIn = hpf;
          }
          else
          {
   notch_0 = _state.voices[v_4].filter_LPF - _state.voices[v_4].filterN_BPF;
   hpf = ((notch_0 * _state.state.filterN_D) - _state.voices[v_4].filterN_LPF);
   _state.voices[v_4].filterN_BPF = (_state.voices[v_4].filterN_BPF + (hpf * FN));
   _state.voices[v_4].filterN_LPF = (_state.voices[v_4].filterN_LPF + (_state.voices[v_4].filterN_BPF * FN));
   satIn = _state.voices[v_4].filterN_LPF;
          }
      }
      if (satIn > 0.0f)
      {
          _state.voices[v_4].saturator_Out = ((satIn < 4.0f) ? (satIn * ((satIn * -0.01666875f) + 0.13335f)) : 0.2667f);
      }
      else
      {
          _state.voices[v_4].saturator_Out = ((satIn > -4.0f) ? (satIn * ((satIn * 0.01666875f) + 0.13335f)) : -0.2667f);
      }
      filter1_Hpf = satIn - _state.voices[v_4].filter1HP_LPF;
      _state.voices[v_4].filter1HP_LPF = (_state.voices[v_4].filter1HP_LPF + (filter1_Hpf * _state.state.filter1HPF));
      voiceOutput = (voiceOutput - (filter1_Hpf * _state.voices[v_4].envelopeA_Out));
  }
  else
  {
      bAA = _state.filterVersion == int32_t {2};
      bBPF = _state.state.filter_HPF;
      _state.voices[v_4].filter_F_Smooth = (_state.voices[v_4].filter_F_Smooth + _state.voices[v_4].filter_F_Inc);
      FM_0 = (_state.state.filter_PM * PolyMod) * _state.voices[v_4].filter_F_Smooth;
      F_0 = intrinsics::max (1.0f, _state.voices[v_4].filter_F_Smooth + FM_0);
      g = Engine__fasttanf (intrinsics::min (1.5f, F_0 * _state.piOverSampleRate));
      norm = 1.0f / (1.0f + g);
      gnorm = g * norm;
      gnorm2 = gnorm * gnorm;
      GF = gnorm2 * gnorm2;
      G = GF * _state.state.filter_K;
      scale = 0.6666667f;
      x_3 = (Mixer * scale) + 0.00001f;
      x_3 = (x_3 * (static_cast<float> (int32_t {1}) + (_state.state.filter_K * 0.1f)));
      s = Array<float, 5> {};
      if (bAA)
      {
          x_ = _state.voices[v_4].filter_X;
          _state.voices[v_4].filter_X = x_3;
          x_3 = ((x_3 + x_) * 0.5f);
          g2 = g + g;
          g2norm = g2 * norm;
          S = _state.voices[v_4].filter_S0 - (g2norm * _state.voices[v_4].filter_S0);
          S = ((((S + _state.voices[v_4].filter_X_1) * g) + _state.voices[v_4].filter_S1) * norm);
          S = ((((S + _state.voices[v_4].filter_X_2) * g) + _state.voices[v_4].filter_S2) * norm);
          S = ((((S + _state.voices[v_4].filter_X_3) * g) + _state.voices[v_4].filter_S3) * norm);
          S = ((((GF * (x_3 + x_3)) + S) - (G * _state.voices[v_4].filter_X_4)) / (static_cast<float> (int32_t {1}) + G));
          S = Engine__tanhaa (S, _state.voices[v_4].filter_X_4, _state.voices[v_4].filter_F0_4);
          x_3 = (x_3 - (S * _state.state.filter_K));
          s[int32_t {0}] = x_3;
          u = (x_3 - _state.voices[v_4].filter_S0) * g2norm;
          _state.voices[v_4].filter_S0 = (_state.voices[v_4].filter_S0 + u);
          x_3 = _state.voices[v_4].filter_S0;
          s[int32_t {1}] = x_3;
          u = (Engine__tanhaa (((x_3 - _state.voices[v_4].filter_S1) - (_state.voices[v_4].filter_X_1 * g)) * norm, _state.voices[v_4].filter_X_1, _state.voices[v_4].filter_F0_1) * g2);
          _state.voices[v_4].filter_S1 = (_state.voices[v_4].filter_S1 + u);
          x_3 = _state.voices[v_4].filter_S1;
          s[int32_t {2}] = x_3;
          u = (Engine__tanhaa (((x_3 - _state.voices[v_4].filter_S2) - (_state.voices[v_4].filter_X_2 * g)) * norm, _state.voices[v_4].filter_X_2, _state.voices[v_4].filter_F0_2) * g2);
          _state.voices[v_4].filter_S2 = (_state.voices[v_4].filter_S2 + u);
          x_3 = _state.voices[v_4].filter_S2;
          s[int32_t {3}] = x_3;
          u = (Engine__tanhaa (((x_3 - _state.voices[v_4].filter_S3) - (_state.voices[v_4].filter_X_3 * g)) * norm, _state.voices[v_4].filter_X_3, _state.voices[v_4].filter_F0_3) * g2);
          _state.voices[v_4].filter_S3 = (_state.voices[v_4].filter_S3 + u);
          x_3 = _state.voices[v_4].filter_S3;
          s[int32_t {4}] = x_3;
      }
      else
      {
          S_0 = (gnorm * (static_cast<float> (int32_t {0}) - _state.voices[v_4].filter_S0)) + _state.voices[v_4].filter_S0;
          S_0 = ((gnorm * (S_0 - _state.voices[v_4].filter_S1)) + _state.voices[v_4].filter_S1);
          S_0 = ((gnorm * (S_0 - _state.voices[v_4].filter_S2)) + _state.voices[v_4].filter_S2);
          S_0 = ((gnorm * (S_0 - _state.voices[v_4].filter_S3)) + _state.voices[v_4].filter_S3);
          S_0 = Engine__fasttanhf (S_0);
          S_0 = (S_0 * _state.state.filter_K);
          x_3 = ((x_3 - S_0) / (static_cast<float> (int32_t {1}) + G));
          s[int32_t {0}] = x_3;
          u_0 = Engine__fasttanhf (x_3 - _state.voices[v_4].filter_S0) * gnorm;
          x_3 = (_state.voices[v_4].filter_S0 + u_0);
          _state.voices[v_4].filter_S0 = (u_0 + x_3);
          s[int32_t {1}] = x_3;
          u_0 = (Engine__fasttanhf (x_3 - _state.voices[v_4].filter_S1) * gnorm);
          x_3 = (_state.voices[v_4].filter_S1 + u_0);
          _state.voices[v_4].filter_S1 = (u_0 + x_3);
          s[int32_t {2}] = x_3;
          u_0 = (Engine__fasttanhf (x_3 - _state.voices[v_4].filter_S2) * gnorm);
          x_3 = (_state.voices[v_4].filter_S2 + u_0);
          _state.voices[v_4].filter_S2 = (u_0 + x_3);
          s[int32_t {3}] = x_3;
          u_0 = (Engine__fasttanhf (x_3 - _state.voices[v_4].filter_S3) * gnorm);
          x_3 = (_state.voices[v_4].filter_S3 + u_0);
          _state.voices[v_4].filter_S3 = (u_0 + x_3);
          s[int32_t {4}] = x_3;
      }
      if (bBPF)
      {
          {
   x_3 = ((s[int32_t {2}] - (static_cast<float> (int32_t {2}) * s[int32_t {3}])) + s[int32_t {4}]);
          }
      }
      x_3 = (x_3 * 3.0f);
      voiceOutput = (voiceOutput + (x_3 * _state.voices[v_4].envelopeA_Out));
  }
         }
         _break_2: {}
         {
  ++v_4;
         }
     }
 }
 if (_state.state.smootherCount > int32_t {0})
 {
     --_state.state.smootherCount;
     _state.state.volumeSmooth = (_state.state.volumeSmooth + _state.state.volumeInc);
     _state.state.delayWetSmooth = (_state.state.delayWetSmooth + _state.state.delayWetInc);
     _state.state.delayDrySmooth = (_state.state.delayDrySmooth + _state.state.delayDryInc);
     _state.state.delayFeedbackSmooth = (_state.state.delayFeedbackSmooth + _state.state.delayFeedbackInc);
 }
 dryOut = voiceOutput * _state.state.delayDrySmooth;
 delayL = {};
 delayR = {};
 if (_state.state.delayActive)
 {
     {
         Hpf_0 = (voiceOutput + (_state.state.delaySum * _state.state.delayFeedbackSmooth)) - _state.state.delay_HPF_LPF;
         _state.state.delay_HPF_LPF = (_state.state.delay_HPF_LPF + ((Hpf_0 * _state.state.delay_HPF_F) + 1e-12f));
         Hpf_0 = (Hpf_0 - _state.state.delay_LPF_LPF);
         _state.state.delay_LPF_LPF = (_state.state.delay_LPF_LPF + (Hpf_0 * _state.state.delay_LPF_F));
     }
     _state.state.delayTime_Mod_1 = (_state.state.delayTime_Mod_1 + _state.state.delayTime_Inc_1);
     _state.state.delayTime_Mod_2 = (_state.state.delayTime_Mod_2 + _state.state.delayTime_Inc_2);
     _state.state.delayTime_Mod_3 = (_state.state.delayTime_Mod_3 + _state.state.delayTime_Inc_3);
     _state.state.delayTime_Mod_4 = (_state.state.delayTime_Mod_4 + _state.state.delayTime_Inc_4);
     _state.delayBuffer[_state.state.delayBufferIn & int32_t {0x1ffff}] = _state.state.delay_LPF_LPF;
     prec1 = _state.state.delayTime_Mod_1;
     trunc1 = static_cast<int32_t> (prec1);
     lo1 = _state.delayBuffer[((_state.state.delayBufferIn - trunc1) & delayMask) & int32_t {0x1ffff}];
     hi1 = _state.delayBuffer[(((_state.state.delayBufferIn - trunc1) - int32_t {1}) & delayMask) & int32_t {0x1ffff}];
     delay1 = lo1 + ((prec1 - static_cast<float> (trunc1)) * (hi1 - lo1));
     prec2 = _state.state.delayTime_Mod_2;
     trunc2 = static_cast<int32_t> (prec2);
     lo2 = _state.delayBuffer[((_state.state.delayBufferIn - trunc2) & delayMask) & int32_t {0x1ffff}];
     hi2 = _state.delayBuffer[(((_state.state.delayBufferIn - trunc2) - int32_t {1}) & delayMask) & int32_t {0x1ffff}];
     delay2 = lo2 + ((prec2 - static_cast<float> (trunc2)) * (hi2 - lo2));
     prec3 = _state.state.delayTime_Mod_3;
     trunc3 = static_cast<int32_t> (prec3);
     lo3 = _state.delayBuffer[((_state.state.delayBufferIn - trunc3) & delayMask) & int32_t {0x1ffff}];
     hi3 = _state.delayBuffer[(((_state.state.delayBufferIn - trunc3) - int32_t {1}) & delayMask) & int32_t {0x1ffff}];
     delay3 = lo3 + ((prec3 - static_cast<float> (trunc3)) * (hi3 - lo3));
     prec4 = _state.state.delayTime_Mod_4;
     trunc4 = static_cast<int32_t> (prec4);
     lo4 = _state.delayBuffer[((_state.state.delayBufferIn - trunc4) & delayMask) & int32_t {0x1ffff}];
     hi4 = _state.delayBuffer[(((_state.state.delayBufferIn - trunc4) - int32_t {1}) & delayMask) & int32_t {0x1ffff}];
     delay4 = lo4 + ((prec4 - static_cast<float> (trunc4)) * (hi4 - lo4));
     _state.state.delayBufferIn = ((_state.state.delayBufferIn + int32_t {1}) & delayMask);
     _state.state.delaySum = (((delay1 + delay2) + delay3) + delay4);
     delayL = (_state.state.delayWetSmooth * (((0.75f * delay1) + (0.25f * delay2)) + delay3));
     delayR = (_state.state.delayWetSmooth * (((0.25f * delay1) + (0.75f * delay2)) + delay4));
 }
 if (_state.testToneActive)
 {
   // std::cout << "Test Tone Active" << std::endl;
     Inc_0 = _state.state.A440Freq;
     _state.state.A440Phase = (_state.state.A440Phase + Inc_0);
     A440_Pulse = {};
     if (_state.state.A440PulseSign != static_cast<float> (int32_t {0}))
     {
         diff = 1.0f - _state.state.A440Phase;
         if (diff > (0.5f * Inc_0))
         {
  A440_Pulse = A440Pulse;
         }
         else
         {
  diffInc_0 = 0.5f + (diff / Inc_0);
  A440_Pulse = (A440Pulse * diffInc_0);
  _state.state.A440Phase = (_state.state.A440Phase - 1.0f);
  _state.state.A440PulseSign = 0.0f;
         }
     }
     else
     {
         diff_0 = 0.5f - _state.state.A440Phase;
         if (diff_0 > (0.5f * Inc_0))
         {
  A440_Pulse = 0.0f;
         }
         else
         {
  A440_Pulse = (A440Pulse * (0.5f - (diff_0 / Inc_0)));
  _state.state.A440PulseSign = 1.0f;
         }
     }
     hpf_0 = (A440_Pulse - 0.83f) - _state.state.A440FilterLPF;
     _state.state.A440FilterLPF = (_state.state.A440FilterLPF + (hpf_0 * _state.state.A440FilterFreq));
     dryOut = (dryOut + _state.state.A440FilterLPF);
 }
 _temp[int32_t {0}] = (_state.state.volumeSmooth * (dryOut + delayL));
 _temp[int32_t {1}] = (_state.state.volumeSmooth * (dryOut + delayR));
 //std::cout << "Output: " << _state.state.volumeSmooth << std::endl;
 _io.out = (_io.out + _temp);
 return;
        }
    }

    float std__intrinsics__clamp (float value, float minimum, float maximum) noexcept
    {
        return (value > maximum) ? maximum : ((value < minimum) ? minimum : value);
    }

    float std__intrinsics__abs (float n) noexcept
    {
        {
 return (n < static_cast<float> (int32_t {0})) ? (- n) : n;
        }
    }

    float Engine__xfade (float x0, float x1, float t) noexcept
    {
        return x0 + ((x1 - x0) * t);
    }

    float Engine__findPWT (float phase0, float width0, float phase1, float width1) noexcept
    {
        return (width0 - phase0) / ((width0 - phase0) - (width1 - phase1));
    }

    void Engine__addBlep0 (Array<float, 8>& buf, int32_t writePos, int32_t mask, float cpos, float halfampl) noexcept
    {
        buf[((writePos - int32_t {2}) & mask) & int32_t {7}] = (buf[((writePos - int32_t {2}) & mask) & int32_t {7}] + (halfampl * Engine__blep0 (static_cast<float> (int32_t {2}) - cpos)));
        buf[((writePos - int32_t {1}) & mask) & int32_t {7}] = (buf[((writePos - int32_t {1}) & mask) & int32_t {7}] + (halfampl * Engine__blep0 (static_cast<float> (int32_t {1}) - cpos)));
        buf[writePos & int32_t {7}] = (buf[writePos & int32_t {7}] - (halfampl * Engine__blep0 (cpos)));
        buf[((writePos + int32_t {1}) & mask) & int32_t {7}] = (buf[((writePos + int32_t {1}) & mask) & int32_t {7}] - (halfampl * Engine__blep0 (cpos + static_cast<float> (int32_t {1}))));
    }

    float Engine__blep0 (float pos) noexcept
    {
        float  x;

        x = 0.5f * pos;
        return (((((((((((((-4.36023f * x) + 13.5038f) * x) - 11.5128f) * x) - 3.25094f) * x) + 7.83529f) * x) - 0.2393f) * x) - 2.97566f) * x) + 0.99986f;
    }

    float std__intrinsics__max (float v1, float v2) noexcept
    {
        {
 return (v1 > v2) ? v1 : v2;
        }
    }

    float Engine__sign (float val) noexcept
    {
        return (val >= static_cast<float> (int32_t {0})) ? 1.0f : -1.0f;
    }

    float Engine__getPhase (float ph2) noexcept
    {
        if (ph2 >= 1.0f)
        {
 return ph2 - 2.0f;
        }
        if (ph2 <= -1.0f)
        {
 return ph2 + 2.0f;
        }
        return ph2;
    }

    float Engine__fasttanf (float x) noexcept
    {
        float  a;
        float  b;

        a = ((((-0.0896638f * x) + 0.0388452f) * x) + 1.00005f) * x;
        b = (((-0.430871f * x) + 0.0404318f) * x) + 1.0f;
        return a / b;
    }

    float Engine__tanhaa (float x, float& xOut, float& outF0) noexcept
    {
        float  x2;
        float  dx;
        float  F0;

        x2 = xOut;
        xOut = x;
        dx = x - x2;
        if (static_cast<double> (intrinsics::abs (dx)) < 0.001)
        {
 x = intrinsics::tanh ((x + x2) * 0.5f);
 outF0 = -2.0f;
        }
        else
        {
 if (outF0 < -1.0f)
 {
     outF0 = ((intrinsics::abs (x2) < static_cast<float> (int32_t {12})) ? intrinsics::log (intrinsics::cosh (x2)) : (x2 - 0.6931472f));
 }
 F0 = (intrinsics::abs (x) < static_cast<float> (int32_t {12})) ? intrinsics::log (intrinsics::cosh (x)) : (x - 0.6931472f);
 x = ((F0 - outF0) / dx);
 outF0 = F0;
        }
        return x;
    }

    float std__intrinsics__tanh (float n) noexcept
    {
        float  e;

        e = intrinsics::exp (intrinsics::min (n, 20.0f) * static_cast<float> (int32_t {2}));
        return (e - static_cast<float> (int32_t {1})) / (e + static_cast<float> (int32_t {1}));
    }

    float std__intrinsics__exp (float n) noexcept
    {
        {
 return 0.0f;
        }
    }

    float std__intrinsics__log (float n) noexcept
    {
        {
 return 0.0f;
        }
    }

    float std__intrinsics__cosh (float n) noexcept
    {
        return 0.5f * (intrinsics::exp (n) + intrinsics::exp (- n));
    }

    float Engine__fasttanhf (float x) noexcept
    {
        float  ax;
        float  x2;
        float  a;
        float  b;

        ax = intrinsics::abs (x);
        if (ax > 4.971787f)
        {
 return (x > static_cast<float> (int32_t {0})) ? 1.0f : -1.0f;
        }
        x2 = x * x;
        a = (((((x2 + static_cast<float> (int32_t {378})) * x2) + static_cast<float> (int32_t {17325})) * x2) + static_cast<float> (int32_t {0x20fdf})) * x;
        b = (((((static_cast<float> (int32_t {28}) * x2) + static_cast<float> (int32_t {3150})) * x2) + static_cast<float> (int32_t {62370})) * x2) + static_cast<float> (int32_t {0x20fdf});
        return a / b;
    }

    //==============================================================================
    const char* getStringForHandle (uint32_t handle, size_t& stringLength)
    {
        (void) handle; (void) stringLength;
        return "";
    }

    //==============================================================================
    #define OFFSETOF(type, member)   ((size_t)((char *)&(*(type *)nullptr).member))
    static _Pro54_State& state_upcast_struct_Pro54_State_struc_fGKm8b (std_midi_MPEConverter_1_State& child) { return *reinterpret_cast<_Pro54_State*> (reinterpret_cast<char*> (std::addressof (child)) - (OFFSETOF (_Pro54_State, _implicit_std__midi__MPEConverter))); }

    //==============================================================================
    static constexpr int32_t noteOffMarker { int32_t {-300} };
    static constexpr int32_t controlPeriod { int32_t {1} };
    static constexpr float envelopeAOffset { -0.02f };
    static constexpr int32_t knobSmoothingTime { int32_t {20} };
    static constexpr float inputVolume { 25.0f };
    double _frequency {};
    const Array<float, 131072> __constant_ { Null() };
    static constexpr float masterVolume { 0.224f };
    const Array<float, 131072> __constant__0 { Null() };
    static constexpr int32_t numVoices { int32_t {32} };
    static constexpr int32_t slideController { int32_t {74} };
    int32_t _sessionID {};
    static constexpr int32_t delayMask { int32_t {0x1ffff} };
    static constexpr float A440Pulse { 1.66f };

    //==============================================================================
    struct intrinsics
    {
        template <typename T> static T modulo (T a, T b)
        {
 if constexpr (std::is_floating_point<T>::value)
     return std::fmod (a, b);
 else
     return a % b;
        }

        template <typename T> static T addModulo2Pi (T a, T b)
        {
 constexpr auto twoPi = static_cast<T> (3.141592653589793238 * 2);
 auto n = a + b;
 return n >= twoPi ? std::remainder (n, twoPi) : n;
        }

        template <typename T> static T abs(T a)   { return std::abs (a); }
        template <typename T> static T min(T a, T b)         { return std::min (a, b); }
        template <typename T> static T max(T a, T b)         { return std::max (a, b); }
        template <typename T> static T clamp         (T a, T b, T c)    { return a < b ? b : (a > c ? c : a); }
        template <typename T> static T wrap          (T a, T b)         { if (b == 0) return 0; auto n = modulo (a, b); if (n < 0) n += b; return n; }
        template <typename T> static T fmod          (T a, T b)         { return b != 0 ? std::fmod (a, b) : 0; }
        template <typename T> static T remainder     (T a, T b)         { return b != 0 ? std::remainder (a, b) : 0; }
        template <typename T> static T floor         (T a)   { return std::floor (a); }
        template <typename T> static T ceil          (T a)   { return std::ceil (a); }
        template <typename T> static T rint          (T a)   { return std::rint (a); }
        template <typename T> static T sqrt          (T a)   { return std::sqrt (a); }
        template <typename T> static T pow(T a, T b)         { return std::pow (a, b); }
        template <typename T> static T exp(T a)   { return std::exp (a); }
        template <typename T> static T log(T a)   { return std::log (a); }
        template <typename T> static T log10         (T a)   { return std::log10 (a); }
        template <typename T> static T sin(T a)   { return std::sin (a); }
        template <typename T> static T cos(T a)   { return std::cos (a); }
        template <typename T> static T tan(T a)   { return std::tan (a); }
        template <typename T> static T sinh          (T a)   { return std::sinh (a); }
        template <typename T> static T cosh          (T a)   { return std::cosh (a); }
        template <typename T> static T tanh          (T a)   { return std::tanh (a); }
        template <typename T> static T asinh         (T a)   { return std::asinh (a); }
        template <typename T> static T acosh         (T a)   { return std::acosh (a); }
        template <typename T> static T atanh         (T a)   { return std::atanh (a); }
        template <typename T> static T asin          (T a)   { return std::asin (a); }
        template <typename T> static T acos          (T a)   { return std::acos (a); }
        template <typename T> static T atan          (T a)   { return std::atan (a); }
        template <typename T> static T atan2         (T a, T b)         { return std::atan2 (a, b); }
        template <typename T> static T isnan         (T a)   { return std::isnan (a) ? 1 : 0; }
        template <typename T> static T isinf         (T a)   { return std::isinf (a) ? 1 : 0; }

        static int32_t reinterpretFloatToInt (float   a)     { int32_t i; memcpy (std::addressof(i), std::addressof(a), sizeof(i)); return i; }
        static int64_t reinterpretFloatToInt (double  a)     { int64_t i; memcpy (std::addressof(i), std::addressof(a), sizeof(i)); return i; }
        static float   reinterpretIntToFloat (int32_t a)     { float   f; memcpy (std::addressof(f), std::addressof(a), sizeof(f)); return f; }
        static double  reinterpretIntToFloat (int64_t a)     { double  f; memcpy (std::addressof(f), std::addressof(a), sizeof(f)); return f; }

        static int32_t rightShiftUnsigned (int32_t a, int32_t b)        { return static_cast<int32_t> (static_cast<uint32_t> (a) >> b); }
        static int64_t rightShiftUnsigned (int64_t a, int64_t b)        { return static_cast<int64_t> (static_cast<uint64_t> (a) >> b); }

        struct VectorOps
        {
 template <typename Vec> static Vec abs     (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::abs (x); }); }
 template <typename Vec> static Vec min     (Vec a, Vec b)     { return a.performBinaryOp (b, [] (auto x, auto y) { return intrinsics::min (x, y); }); }
 template <typename Vec> static Vec max     (Vec a, Vec b)     { return a.performBinaryOp (b, [] (auto x, auto y) { return intrinsics::max (x, y); }); }
 template <typename Vec> static Vec sqrt    (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::sqrt (x); }); }
 template <typename Vec> static Vec log     (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::log (x); }); }
 template <typename Vec> static Vec log10   (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::log10 (x); }); }
 template <typename Vec> static Vec sin     (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::sin (x); }); }
 template <typename Vec> static Vec cos     (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::cos (x); }); }
 template <typename Vec> static Vec tan     (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::tan (x); }); }
 template <typename Vec> static Vec sinh    (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::sinh (x); }); }
 template <typename Vec> static Vec cosh    (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::cosh (x); }); }
 template <typename Vec> static Vec tanh    (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::tanh (x); }); }
 template <typename Vec> static Vec asinh   (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::asinh (x); }); }
 template <typename Vec> static Vec acosh   (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::acosh (x); }); }
 template <typename Vec> static Vec atanh   (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::atanh (x); }); }
 template <typename Vec> static Vec asin    (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::asin (x); }); }
 template <typename Vec> static Vec acos    (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::acos (x); }); }
 template <typename Vec> static Vec atan    (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::atan (x); }); }
 template <typename Vec> static Vec atan2   (Vec a, Vec b)     { return a.performBinaryOp (b, [] (auto x, auto y) { return intrinsics::atan2 (x, y); }); }
 template <typename Vec> static Vec pow     (Vec a, Vec b)     { return a.performBinaryOp (b, [] (auto x, auto y) { return intrinsics::pow (x, y); }); }
 template <typename Vec> static Vec exp     (Vec a) { return a.performUnaryOp ([] (auto x) { return intrinsics::exp (x); }); }
        };
    };

    static constexpr float  _inf32  =  std::numeric_limits<float>::infinity();
    static constexpr double _inf64  =  std::numeric_limits<double>::infinity();
    static constexpr float  _ninf32 = -std::numeric_limits<float>::infinity();
    static constexpr double _ninf64 = -std::numeric_limits<double>::infinity();
    static constexpr float  _nan32  =  std::numeric_limits<float>::quiet_NaN();
    static constexpr double _nan64  =  std::numeric_limits<double>::quiet_NaN();

    //==============================================================================
    #if __clang__
     #pragma clang diagnostic pop
    #elif __GNUC__
     #pragma GCC diagnostic pop
    #else
     #pragma warning (pop)
    #endif
};

inline void setPatch(Pro54& p, std::map<std::string, float> patch) 
{
  for (auto& [key, value] : patch)
  {
    auto ep = Pro54::inputEndpoints[Pro54::getEndpointHandleForName(key)-1];
    p.addEvent(ep.handle, (unsigned int)ep.endpointType, (unsigned char*)&value);
  }  
}
