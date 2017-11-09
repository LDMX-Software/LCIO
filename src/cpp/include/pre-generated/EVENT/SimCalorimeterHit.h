// -*- C++ -*-
// AID-GENERATED
// =========================================================================
// This class was generated by AID - Abstract Interface Definition          
// DO NOT MODIFY, but use the org.freehep.aid.Aid utility to regenerate it. 
// =========================================================================
#ifndef EVENT_SIMCALORIMETERHIT_H
#define EVENT_SIMCALORIMETERHIT_H 1

#include "EVENT/LCObject.h"
#include "empty_ignore.h"

namespace EVENT {

class MCParticle;

/** The generic simulated calorimeter hit. 
 * 
 * @author gaede
 * @version $Id: SimCalorimeterHit.aid,v 1.8 2006-03-24 13:25:52 gaede Exp $
 */

class SimCalorimeterHit : public LCObject {

public: 
    /// Destructor.
    virtual ~SimCalorimeterHit() { /* nop */; }


    /** Useful typedef for template programming with LCIO */
    typedef SimCalorimeterHit lcobject_type ;

    /**Returns the detector specific (geometrical) cell id.
     */
    virtual int getCellID0() const = 0;

    /**Returns the second detector specific (geometrical) cell id.
     *  0 if information is not stored -  check the flag word (bit CHBIT_ID1) 
     *  of the collection. Default is to store only cellid0.
     */
    virtual int getCellID1() const = 0;

    /** Returns the energy of the hit in [GeV].
     */
    virtual float getEnergy() const = 0;

    /** Returns the position of the hit in world coordinates.
     *  NULL if information is not stored -  check the flag word (bit CHBIT_LONG) 
     *  of the collection.
     */
    virtual const float* getPosition() const = 0;

    /** Returns the position where the energy deposited (step) occurred
     * optional, only if bit LCIO::CHBIT_STEP is set.   
     */
    virtual const float* getStepPosition(int i) const = 0;

    /** Returns the number of MC contributions to the hit. 0 if 
     * information is not stored. Renamed to getNMCContributions.
     * @deprecated
     * @see getNMCContributions()
     */
    virtual int getNMCParticles() const = 0;

    /** Returns the number of MC contributions to the hit. 0 if 
     * information is not stored. There are two levels of detail: if 
     * collection flag bit LCIO.CHBIT_STEP==1 then all simulator steps' 
     * contributions to the hit are stored, otherwise there is only one 
     * contribution for every particle entering the calorimeter.
     */
    virtual int getNMCContributions() const = 0;

    /** Returns the energy in [GeV] of the i-th contribution to the hit.
     * @see getNMCContributions()
     */ 
    virtual float getEnergyCont(int i) const = 0;

    /** Returns the time in [ns] of the i-th contribution to the hit.
     * @see getNMCContributions()
     */
    virtual float getTimeCont(int i) const = 0;

    /** Returns the step length of the i-th contribution to the hit.
     * @see getNMCContributions()
     */
    virtual float getLengthCont(int i) const = 0;

    /** Returns the PDG code of the shower particle that caused this contribution.
     *  Check the flag word bit LCIO.CHBIT_STEP of the collection whether this information 
     *  is available. 
     * @see getNMCContributions()
     */ 
    virtual int getPDGCont(int i) const = 0;

    /** Returns the MCParticle that caused the shower responsible for this contribution to the hit.
     *  This is the particle that flew into the calorimeter and not the shower particle that made the 
     *  energy deposition.
     * @see getNMCContributions()
     */
    virtual MCParticle * getParticleCont(int i) const = 0;
}; // class
} // namespace EVENT
#endif /* ifndef EVENT_SIMCALORIMETERHIT_H */
