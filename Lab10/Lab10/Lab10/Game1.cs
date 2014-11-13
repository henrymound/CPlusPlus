using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;
using ExplodingTeddies; 

namespace Lab10
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {

        //declare the window width and height constant values
        const int WINDOW_WIDTH = 800;
        const int WINDOW_HEIGHT = 600; 
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;
        TeddyBear bear1, bear2;//creates two TeddyBear objects
        Explosion explosionion1;//creates an explosion object

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";

            //set the window width and height to the previously defined values
            graphics.PreferredBackBufferWidth = WINDOW_WIDTH;
            graphics.PreferredBackBufferHeight = WINDOW_HEIGHT;
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here

            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);
            /*Declares two TeddyBear values with different images, starting positions, and velocities (Vector2 is the velocity)*/
            bear1 = new TeddyBear(Content, WINDOW_WIDTH, WINDOW_HEIGHT, "orange", 800, 600, new Vector2(8, 5));
            bear2 = new TeddyBear(Content, WINDOW_WIDTH, WINDOW_HEIGHT, "red", 0, 0, new Vector2(4, 7));
            //Creates an explosion object with the same content manager as the bears
            explosionion1 = new Explosion(Content); 
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// all content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            // Allows the game to exit
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed)
                this.Exit();
            //updates the game everytime the compiler calls the Update() method - animates the bears
            bear1.Update();
            bear2.Update();
            if (
                (/*A set of conditional statesments used to detect if the two bears are within
                  * 40 pixels of eachother (20 pixel bounding box from the center of each bear).
                  * If they are close to eachother, then there will be an explosion!*/
                (bear1.DrawRectangle.Location.Y < (bear2.DrawRectangle.Location.Y + 20))
                &&(bear1.DrawRectangle.Location.Y > (bear2.DrawRectangle.Location.Y - 20))
                )
                &&
                (
                (bear1.DrawRectangle.Location.X < (bear2.DrawRectangle.Location.X + 20))
                &&(bear1.DrawRectangle.Location.X > (bear2.DrawRectangle.Location.X - 20))
                )
            ) {
                //deactivates bear before explosion
                bear1.Active = false;
                bear2.Active = false;
                //creates an explosion between the bears
                explosionion1.Play( (bear1.DrawRectangle.Center.X + bear2.DrawRectangle.Center.X)/2,
                                    (bear1.DrawRectangle.Center.Y + bear2.DrawRectangle.Center.Y)/2);
                //resets location when the bears collide
                bear1 = new TeddyBear(Content, WINDOW_WIDTH, WINDOW_HEIGHT, "orange", 300, 500, new Vector2(8, 5));
                bear2 = new TeddyBear(Content, WINDOW_WIDTH, WINDOW_HEIGHT, "red", 200, 100, new Vector2(4, 7));
            }
            //updates explosion when it is being animated
            explosionion1.Update(gameTime);
            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.Azure);
            //code to draw the bears and explosion using spriteBatch, spriteBatch then terminates itself after drawing.
            spriteBatch.Begin();
            bear1.Draw(spriteBatch);
            bear2.Draw(spriteBatch);
            explosionion1.Draw(spriteBatch);
            spriteBatch.End();
            base.Draw(gameTime);
        }
    }
}
