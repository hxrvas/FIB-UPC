using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Roll : MonoBehaviour
{

    public float velocity=50;
    // Update is called once per frame
    void Update()
    {
       transform.Rotate(-velocity*Time.deltaTime, 0f, 0f);
    }
}
