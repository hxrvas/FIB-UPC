using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OscillateMartillo : MonoBehaviour
{

    public float velocity = 3f;
    public bool baixar = true;
    // Update is called once per frame
    void Update()
    {
        if (transform.rotation.z >= 0.99) baixar = true;
        else if (transform.rotation.z < 0.6) baixar = false;
        Vector3 z = new Vector3(0, 0, 1);
        if (baixar) transform.Rotate(z, -velocity *  Time.deltaTime);
        else transform.Rotate(z, velocity *Time.deltaTime);
    }
}
